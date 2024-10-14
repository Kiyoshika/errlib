#include "result.h"

#include <stdio.h>
#include <assert.h>

ResultBool copy_fail()
{
    ResultBool result;
    RESULT_SET_ERROR(result, "something happened");

    return result;
}

ResultBool copy_success()
{
    ResultBool result;
    RESULT_SET_SUCCESS(result, true);

    return result;
}

void inplace_fail(ResultBool* result)
{
    RESULT_SET_ERROR(*result, "something happened");
}

void inplace_success(ResultBool* result)
{
    RESULT_SET_SUCCESS(*result, true);
}

int main()
{
    // copy - fail
    ResultBool result = copy_fail();
    assert(result.info.is_error == true);
    assert(strcmp(result.info.msg, "something happened") == 0);

    // copy - success
    result = copy_success();
    assert(result.info.is_error == false);
    assert(result.info.msg == NULL);
    assert(result.value == true);

    // inplace - fail
    inplace_fail(&result);
    assert(result.info.is_error == true);
    assert(strcmp(result.info.msg, "something happened") == 0);
    
    // inplace - success
    inplace_success(&result);
    assert(result.info.is_error == false);
    assert(result.info.msg == NULL);
    assert(result.value == true);

    return 0;
}
