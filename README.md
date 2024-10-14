# Errlib - A barebones error result library
This is an incredibly lightweight header-only error result library in C.

## Usage
Use one of result structs and provided macros to either set an error with a message or set a success with the value of the appropriate type.

This supports "copy" style (returning structs) or "inplace" style (writing result pointers). See below examples for both styles:

### "Copy" Style (Returning Result Structs)
```c
#include <stdio.h>

#include "result.h" // result types and macros

ResultInt32 divide(int32_t a, int32_t b)
{
    ResultInt32 result;

    if (b == 0)
    {
        RESULT_SET_ERROR(result, "b cannot be 0 when dividing.\n");
        return result;
    }

    RESULT_SET_SUCCESS(result, a/b);
    return result;
}

int main()
{
    ResultInt32 result = divide(3, 0);
    if (result.info.is_error)
    {
        fprintf(stderr, result.info.msg);
        return -1;
    }

    printf("Division: %d\n", result.value);
    return 0;
}
```

### "Inplace" Style (Writing Result Pointers)
If you prefer not to return structs, then you can slightly modify above to modify pointers. Just note that the macros expect a direct value to the struct and not a pointer.
```c
#include <stdio.h>

#include "result.h" // result types and macros

void divide(int32_t a, int32_t b, ResultInt32* result)
{
    if (b == 0)
    {
        RESULT_SET_ERROR(*result, "b cannot be 0 when dividing.\n");
        return;
    }

    RESULT_SET_SUCCESS(*result, a/b);
}

int main()
{
    ResultInt32 result;

    divide(3, 0, &result);

    if (result.info.is_error)
    {
        fprintf(stderr, result.info.msg);
        return -1;
    }

    printf("Division: "%d\n", result.value);
    return 0;
}
```

## Note aboute error messages
Error messages just copy the pointer, i.e., `result.info.msg = message_value`. You must take care to ensure you provide a valid `message_value` to avoid reading invalid/free'd pointers.

## Note about strings
There are two string types:
* `ResultOwnedString`
    * This labels a heap-allocated string that **YOU** must free. E.g., `free(result.value)` after usage.
* `ResultReadString`
    * This labels a read-only string that **DOES NOT** need to be free'd.

Functionally, these are the exact same, but the difference in naming is for programmer's convenience and clarify what contains ownership or doesn't.

## Result Types
It's best to just look at the [header](include/result.h) to see the list of all types. It's essentially all the basic C types with the special exceptions for strings noted above.

## Installing
This is a single header file, `result.h`. You can just download this header directory or clone/submodule this repo to grab it and include it.
