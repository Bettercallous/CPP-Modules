

//         10    6    9    3    +    -11    *    /    *    17    +    5    +

//         ((10 * (6 / ((9 + 3) * -11))) + 17) + 5


/*
    Accessing all elements in the array, if the element is not matching with the special character (‘+’, ‘-‘,’*’, ‘/’)
    then push the element to the stack.
    Then whenever the special character is found then pop the first two-element from the stack and perform the action and then push
    the element to stack again.
    Repeat the above two process to all elements in the array
    At last pop the element from the stack and print the Result

*/

// 42

//