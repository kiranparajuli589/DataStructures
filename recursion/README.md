# Recursion

Recursion refers to a process by which a function or a subroutine calls itself as a part of its execution. It is a powerful technique used in programming where a function is defined in terms of itself, allowing the problem to be solved by breaking it down into smaller instances of the same problem.

## Principles of Recursion

A class of object or methods exhibits recursive behavior when it can be defined by the following two properties:

- A simple base case (or cases) — a terminating scenario that does not use recursion to produce an answer
- A recursive step - a set of rules that reduces all other cases towards the base case

## Examples of Recursion

- Factorial
- Fibonacci
- Tower of Hanoi

## Factorial

```
procedure factorial(n)
    if n = 0
        return 1
    else
        return n * factorial(n - 1)
    end if
end procedure
```

## Fibonacci

```
procedure fibonacci(limit)
    if limit = 0 and limit = 1
        return limit
    else
        return fibonacci(limit - 1) + fibonacci(limit - 2)
    end if
end procedure
```

## Tower of Hanoi

### Rules
- Only one disk can be moved at a time.
- Larger disks cannot be placed on top of smaller disks.
- Only the top disk can be moved.

### Algorithm

Assuming `n` disks are distributed in valid arrangements among the pegs. To move the disks from a source peg to a target peg using a spare peg, without violating the rules, we can follow the following steps:

- Move the top `n-1` disks from the source peg to the spare peg using the target peg.

- Move the remaining disk from the source peg to the target peg.

- Move the `n-1` disks from the spare peg to the target peg using the source peg.

```
procedure toh(n, source, target, spare)
    if n = 1
        move disk from source to target
    else
        toh(n-1, source, spare, target)
        move disk "n" from source to target
        toh(n-1, spare, target, source)
    end if
end procedure
```