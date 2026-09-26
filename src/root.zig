const std = @import("std");
const testing = std.testing;

pub const LinkedList = @import("structures/linked_list.zig");

test "basic add functionality" {
    testing.refAllDecls(LinkedList);
}
