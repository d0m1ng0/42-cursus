
Mandatory part

Reminder: During the defense, no segmentation faults, unexpected crashes, premature terminations, or uncontrolled exits are allowed. Otherwise, the final grade will be 0. Use the appropriate flag. This rule applies throughout the entire defense.
README.md Compliance check

Does the repository contain a README.md file at its root, and does it include all of the following?

    The first line is italicized and formatted exactly as: This project has been created as part of the 42 curriculum by <login1>.
    A "Description" section explaining the project's purpose and providing a brief overview.
    An "Instructions" section with relevant details about compilation, installation, and/or execution.
    A "Resources" section listing references (documentation, tutorials, etc.) and explaining how AI was used, specifying for which tasks and which parts of the project.

Memory leaks

Throughout the defense, monitor the memory usage of push_swap
(e.g., using the top command) to detect anomalies and ensure that
all allocated memory is properly freed. If there is one memory leak
(or more), the final grade is 0.

Error management

In this section, we'll evaluate the push_swap's error management.
If at least one fails, no points will be awarded for this
section. Move to the next one.

    Run push_swap with non numeric parameters. The program must
    display "Error" followed by a ’\n’ on the standard error.

    Run push_swap with a duplicate numeric parameter. The program
    must display "Error" followed by a ’\n’ on the standard error.

    Run push_swap with only numeric parameters including one greater
    than MAXINT. The program must display "Error" followed by a ’\n’
    on the standard error.

    Run push_swap without any parameters. The program must not
    display anything and give the prompt back.

Push_swap - Identity test

In this section, we will evaluate push_swap's behavior when given
an already sorted list. Execute the following tests.
If at least one fails, no points will be awarded for this
section. Move to the next one.

    Run the following command "$>./push_swap 42".
    The program should display nothing (0 instruction).

    Run the following command "$>./push_swap 2 3".
    The program should display nothing (0 instruction).

    Run the following command "$>./push_swap 0 1 2 3".
    The program should display nothing (0 instruction).

    Run the following command "$>./push_swap 0 1 2 3 4 5 6 7 8
    9".
    The program should display nothing (0 instruction).

    Run the following command "$>./push_swap <Between 0 and 9 randomly
    chosen sorted values>".
    The program should display nothing (0 instruction).

Push_swap - Simple version

If the following tests fail, no points will be awarded for this
section. Move to the next one. Use the checker binary provided in the
attachments.

    Run "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG".
    Check that the checker program displays "OK" and that the
    size of the list of instructions from push_swap is 2 OR 3.
    Otherwise the test fails.

    Run "$>ARG="<Between 0 and 3 randomly chosen values>"; ./push_swap
    $ARG | ./checker_OS $ARG".
    Check that the checker program displays
    "OK" and that the size of the list of instructions from push_swap
    is between 0 AND 3. Otherwise the test fails.

Another simple version

Execute the following 2 tests. If at least one fails, no points
will be awarded for this section. Move to the next one. Use the checker
binary provided in the attachments.

    Run "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG".
    Check that the checker program displays "OK" and that the
    size of the instruction list from push_swap does not exceed 12.
    Kudos if the instruction list contains only 8 steps.

    Run "$>ARG="<5 random values>"; ./push_swap $ARG | ./checker_OS
    $ARG" and replace the placeholder by 5 random valid values.

    Check that the checker program displays "OK" and that the
    size of the list of instructions from push_swap isn't more
    than 12. Otherwise this test fails. You'll have to
    specifically check that the program wasn't developed to only
    answer correctly on the test included in this scale. You
    should repeat this test couple of times with several
    permutations before you validate it.

Push_swap - Middle version

If the following test fails, no points will be awarded for this
section. Move to the next one. Use the checker
binary provided in the attachments.

    Run "$>ARG="<100 random values>"; ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 100 random valid values. Check that the checker program displays "OK" and that the size of the list of instructions. Give points in accordance:
        less than 700: 5
        less than 900: 4
        less than 1100: 3
        less than 1300: 2
        less than 1500: 1 You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test multiple times with different permutations before validating it.

Rate it from 0 (failed) through 5 (excellent)
Push_swap - Advanced version

If the following test fails, no points will be awarded for this
section. Move to the next one. Use the checker
binary provided in the attachments.

    Run "$>ARG="<500 random values>"; ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 500 random valid values (One is not called John/Jane Script for nothing). Check that the checker program displays "OK" and the number of instructions is within the following limits:
        less than 5500: 5
        less than 7000: 4
        less than 8500: 3
        less than 10000: 2
        less than 11500: 1 You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it.

Rate it from 0 (failed) through 5 (excellent)
Bonus

Reminder : Remember that for the duration of the defence, no segfault, nor other unexpected, premature, uncontrolled or unexpected termination of the program, else the final grade is 0. Use the appropriate flag. This rule is active throughout the whole defence. We will look at your bonuses if and only if your mandatory part is EXCELLENT. This means that you must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or bad usage.If the mandatory part does not receive a perfect score during this defense, the bonus section will be completely ignored.
Checker program - Error management

In this section, we'll evaluate the checker's error management.
If at least one fails, no points will be awarded for this
section. Move to the next one.

    Run checker with non numeric parameters. The program must
    display "Error" followed by a ’\n’ on the standard error.

    Run checker with a duplicate numeric parameter. The program
    must display "Error" followed by a ’\n’ on the standard error.

    Run checker with only numeric parameters including one greater
    than MAXINT. The program must display "Error" followed by a
    ’\n’ on the standard error.

    Run checker without any parameters. The program must not
    display anything and give the prompt back.

    Run checker with valid parameters, and write an action that
    doesn't exist during the instruction phase. The program must
    display "Error" followed by a ’\n’ on the standard error.

    Run checker with valid parameters, and write an action with
    one or several spaces before and/or after the action during
    the instruction phase. The program must display "Error"
    followed by a ’\n’ on the standard error.

Checker program - False tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that doesn't sort the list. Execute the
following 2 tests. If at least one fails, no points will be
awarded for this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
instruction phase.

    Run checker with the following command "$>./checker 0 9 1 8 2
    7 3 6 4 5" then write the following valid action list "[sa,
    pb, rrr]". The checker should display "KO".

    Run checker with a valid list as parameter of your choice then
    write a valid instruction list that doesn't order the
    integers.The checker should display "KO". You'll have to
    specifically check that the program wasn't developed to only
    answer correctly on the test included in this scale. You
    should repeat this test couple of times with several
    permutations before you validate it.

Checker program - Right tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that sort the list. Execute the following
2 tests. If at least one fails, no points will be awarded for
this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
instruction phase.

    Run checker with the following command "$>./checker 0 1 2"
    then press CTRL+D without writing any instruction. The program
    should display "OK".

    Run checker with the following command "$>./checker 0 9 1 8 2"
    then write the following valid action list "[pb, ra, pb, ra,
    sa, ra, pa, pa]". The program should display "OK".

    Run checker with a valid list as parameter of your choice then
    write a valid instruction list that correctly orders the integers.
    Checker must display "OK". You'll have to specifically check
    that the program wasn't developed to only answer correctly on
    the test included in this scale. You should repeat this test
    couple of times with several permutations before you validate
    it.

