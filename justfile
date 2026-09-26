set dotenv-load := true

default:
    @echo "No default task specified. Please choose a task to run."

test:
    @echo "Running Test Suite"
    @zig build test
