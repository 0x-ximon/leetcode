const std = @import("std");
const mem = std.mem;
const testing = std.testing;

fn Node(comptime T: type) type {
    return struct {
        value: T,
        next: ?*Node(T),
        prev: ?*Node(T),
    };
}

/// A doubly linked list of `T` that allocates and owns its own nodes.
/// Construct with `empty`; free remaining nodes with `deinit`.
pub fn LinkedList(comptime T: type) type {
    return struct {
        const Self = @This();

        head: ?*N,
        tail: ?*N,
        length: usize,

        /// The node type for this list.
        const N = Node(T);

        /// Selects which end of the list an operation applies to.
        const D = enum {
            Front,
            Back,
        };

        pub const empty: Self = .{
            .head = null,
            .tail = null,
            .length = 0,
        };

        const Errors = error{
            InvalidIndex,
            NotImplemented,
        };

        /// Frees every node. Does not free values that themselves own memory.
        pub fn deinit(self: Self, allocator: mem.Allocator) void {
            var cursor = self.head;
            while (cursor) |node| {
                const next = node.next;
                allocator.destroy(node);
                cursor = next;
            }
        }

        /// Inserts `value` at the given end: `.Front` prepends, `.Back` appends. O(1).
        pub fn add(self: *Self, allocator: mem.Allocator, direction: D, value: T) !void {
            const node = try allocator.create(N);
            node.* = N{
                .next = null,
                .prev = null,
                .value = value,
            };

            switch (self.length) {
                0 => {
                    self.head = node;
                    self.tail = node;
                },

                else => {
                    switch (direction) {
                        .Front => {
                            const head = self.head;
                            head.?.prev = node;
                            node.next = head;
                            self.head = node;
                        },
                        .Back => {
                            const tail = self.tail;
                            tail.?.next = node;
                            node.prev = tail;
                            self.tail = node;
                        },
                    }
                },
            }

            self.length += 1;
        }

        /// Removes and returns the value at the given end (`.Front` removes the head,
        /// `.Back` removes the tail), or `null` if the list is empty. O(1).
        pub fn pop(self: *Self, allocator: mem.Allocator, direction: D) ?T {
            var result: ?T = null;

            switch (self.length) {
                0 => return null,

                1 => {
                    const head = self.head.?;
                    result = head.value;
                    allocator.destroy(head);

                    self.head = null;
                    self.tail = null;
                },

                else => {
                    switch (direction) {
                        .Front => {
                            const head = self.head.?;
                            result = head.value;

                            self.head = head.next;
                            self.head.?.prev = null;

                            allocator.destroy(head);
                        },

                        .Back => {
                            const tail = self.tail.?;
                            result = tail.value;

                            self.tail = tail.prev;
                            self.tail.?.next = null;

                            allocator.destroy(tail);
                        },
                    }
                },
            }

            self.length -= 1;
            return result;
        }

        /// Returns the value at `index` (0-based from the head), or `error.InvalidIndex`
        /// if `index >= length`. O(n).
        pub fn get(self: *Self, index: usize) Errors!T {
            if (index >= self.length) return Errors.InvalidIndex;
            var cursor = self.head;

            var i: usize = 0;
            while (cursor) |node| {
                if (index == i) return node.value;
                cursor = node.next;
                i += 1;
            } else unreachable;
        }

        /// Overwrites the value at `index`, or returns `error.InvalidIndex`
        /// if `index >= length`. O(n).
        pub fn set(self: *Self, index: usize, value: T) Errors!void {
            if (self.length == 0) return Errors.InvalidIndex;
            if (index >= self.length) return Errors.InvalidIndex;
            var cursor = self.head;

            var i: usize = 0;
            while (cursor) |node| {
                if (index == i) {
                    node.value = value;
                    return;
                }

                cursor = node.next;
                i += 1;
            } else unreachable;
        }

        /// Inserts `value` so it becomes the element at `index`, shifting the elements
        /// that were at `index..length` back by one. `index == length` appends.
        /// Returns `error.InvalidIndex` if `index > length`. O(n).
        pub fn put(self: *Self, allocator: mem.Allocator, index: usize, value: T) !void {
            if (index > self.length) return Errors.InvalidIndex;
            if (index == 0) return self.add(allocator, .Front, value);
            if (index == self.length) return self.add(allocator, .Back, value);

            const node = try allocator.create(N);
            node.* = N{
                .next = null,
                .prev = null,
                .value = value,
            };

            var i: usize = 0;
            var cursor = self.head;
            while (cursor) |curr| {
                if (index == i) break;
                cursor = curr.next;
                i += 1;
            }

            // Insert to the left of cursor at this point
            cursor.?.prev.?.next = node;
            node.prev = cursor.?.prev;
            node.next = cursor;
            cursor.?.prev = node;

            self.length += 1;
        }

        /// Removes and returns the value at `index`, shifting later elements forward
        /// by one. Returns `error.InvalidIndex` if `index >= length`. O(n).
        pub fn rid(self: *Self, allocator: mem.Allocator, index: usize) !T {
            if (self.length == 0) return Errors.InvalidIndex;
            if (index >= self.length) return Errors.InvalidIndex;
            if (index == 0) return self.pop(allocator, .Front) orelse unreachable;
            if (index == self.length - 1) return self.pop(allocator, .Back) orelse unreachable;

            var i: usize = 0;
            var cursor = self.head;
            while (cursor) |curr| {
                if (index == i) break;
                cursor = curr.next;
                i += 1;
            }

            // Delete node at this point
            const node = cursor.?;
            node.prev.?.next = node.next;
            node.next.?.prev = node.prev;

            const result = node.value;
            allocator.destroy(node);

            self.length -= 1;
            return result;
        }

        /// Returns the index of the first occurrence of `value` searching from the
        /// head, or `null` if it is not present. O(n).
        pub fn has(self: *Self, value: T) ?usize {
            if (self.length == 0) return null;

            var i: usize = 0;
            var it = self.iter(.Front);
            while (it.next()) |v| {
                if (v == value) return i;
                i += 1;
            }

            return null;
        }

        pub fn len(self: *Self) usize {
            return self.length;
        }

        /// Returns a newly allocated slice of all values in head-to-tail order.
        /// Caller owns the returned memory.
        pub fn items(self: *Self, allocator: mem.Allocator) ![]T {
            var list: std.ArrayList(T) = .empty;
            defer list.deinit(allocator);

            var cursor = self.head;
            while (cursor) |node| {
                try list.append(allocator, node.value);
                cursor = node.next;
            }

            return list.toOwnedSlice(allocator);
        }

        /// Returns an iterator starting at the head (`.Front`) or tail (`.Back`).
        /// Pair `.Front` with `Iterator.next` and `.Back` with `Iterator.prev` to walk
        /// the full list; the other method on a given start point stops immediately.
        pub fn iter(self: *Self, direction: D) Iterator {
            switch (direction) {
                .Front => {
                    const node = self.head;
                    return .{ .node = node };
                },
                .Back => {
                    const node = self.tail;
                    return .{ .node = node };
                },
            }
        }

        const Iterator = struct {
            node: ?*N,

            /// Returns the current value and advances toward the tail, or `null`
            /// once the end is reached.
            pub fn next(self: *Iterator) ?T {
                if (self.node) |node| {
                    const value = node.value;
                    self.node = node.next;
                    return value;
                }

                return null;
            }

            /// Returns the current value and advances toward the head, or `null`
            /// once the end is reached.
            pub fn prev(self: *Iterator) ?T {
                if (self.node) |node| {
                    const value = node.value;
                    self.node = node.prev;
                    return value;
                }

                return null;
            }
        };
    };
}

const Context = struct {
    const Self = @This();

    const T = i32;
    const L = LinkedList(T);
    const D = L.D;
    const E = L.Errors;

    const Errors = error{
        AllocationFailed,
        ViolatedChainInvariant,
    };

    fn nodesInvariantsHold(list: *L) Errors!void {
        const length = list.len();

        {
            var iter = list.iter(.Front);
            var visited: u64 = 0;
            while (iter.next()) |_| visited += 1;
            if (visited != length) return Errors.ViolatedChainInvariant;
        }

        {
            var iter = list.iter(.Back);
            var visited: u64 = 0;
            while (iter.prev()) |_| visited += 1;
            if (visited != length) return Errors.ViolatedChainInvariant;
        }
    }
};

fn testLinkedList(_: Context, smith: *std.testing.Smith) !void {
    const allocator = testing.allocator;

    var oracle: std.ArrayList(Context.T) = .empty;
    defer oracle.deinit(allocator);

    var list: Context.L = .empty;
    defer list.deinit(allocator);

    const Operations = enum { add, pop, get, set, put, rid, has };
    while (!smith.eos()) {
        const n = oracle.items.len;
        const op = smith.value(Operations);

        const value = smith.value(Context.T);
        const direction = smith.value(Context.D);
        const index = smith.valueRangeAtMost(u8, 0, 0x20);

        switch (op) {
            .add => {
                switch (direction) {
                    .Front => {
                        try oracle.insert(allocator, 0, value);
                        try list.add(allocator, .Front, value);
                    },
                    .Back => {
                        try oracle.append(allocator, value);
                        try list.add(allocator, .Back, value);
                    },
                }
            },

            .pop => {
                switch (direction) {
                    .Front => {
                        if (oracle.items.len == 0) {
                            const actual = list.pop(allocator, .Front);
                            try testing.expectEqual(null, actual);
                            continue;
                        }

                        const expected = oracle.orderedRemove(0);
                        const actual = list.pop(allocator, .Front) orelse unreachable;
                        try testing.expectEqual(expected, actual);
                    },
                    .Back => {
                        const expected = oracle.pop();
                        const actual = list.pop(allocator, .Back);
                        try testing.expectEqual(expected, actual);
                    },
                }
            },

            .get => {
                if (index < n) {
                    const expected = oracle.items[index];
                    const actual = list.get(index) catch unreachable;
                    try testing.expectEqual(expected, actual);
                } else {
                    const actual = list.get(index);
                    try testing.expectError(Context.E.InvalidIndex, actual);
                }
            },

            .set => {
                if (index < n) {
                    oracle.items[index] = value;
                    list.set(index, value) catch unreachable;

                    const expected = oracle.items[index];
                    const actual = list.get(index) catch unreachable;
                    try testing.expectEqual(expected, actual);
                } else {
                    const actual = list.set(index, value);
                    try testing.expectError(Context.E.InvalidIndex, actual);
                }
            },

            .put => {
                if (index <= n) {
                    try oracle.insert(allocator, index, value);
                    try list.put(allocator, index, value);

                    const expected = oracle.items[index];
                    const actual = list.get(index) catch unreachable;
                    try testing.expectEqual(expected, actual);
                } else {
                    const actual = list.put(allocator, index, value);
                    try testing.expectError(Context.E.InvalidIndex, actual);
                }
            },

            .rid => {
                if (index < n) {
                    const expected = oracle.orderedRemove(index);
                    const actual = try list.rid(allocator, index);
                    try testing.expectEqual(expected, actual);
                } else {
                    const actual = list.rid(allocator, index);
                    try testing.expectError(Context.E.InvalidIndex, actual);
                }
            },

            .has => {
                const expected: ?usize = block: {
                    for (0.., oracle.items) |i, v| {
                        if (v == value) break :block i;
                    } else break :block null;
                };
                const actual = list.has(value);

                try testing.expectEqual(expected, actual);
            },
        }

        const expected = oracle.items;
        const actual = try list.items(allocator);
        defer allocator.free(actual);

        try testing.expectEqual(expected.len, actual.len);
        try testing.expectEqualSlices(Context.T, expected, actual);

        // Validate Invariants Integrity
        try Context.nodesInvariantsHold(&list);
    }
}

test "LinkedList: Fuzz" {
    try testing.fuzz(Context{}, testLinkedList, .{});
}
