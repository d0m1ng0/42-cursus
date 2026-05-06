Introduction
Please comply with the following rules:

- Remain polite, courteous, respectful, and constructive throughout the
evaluation process. The well-being of the community depends on it.

- Work with the student or group whose project is being evaluated to
identify potential issues. Take the time to discuss and debate the
problems that may have been identified.

- You must consider that there might be some differences in how your peers
might have understood the project's instructions and the scope of its
functionalities. Always keep an open mind and grade them as honestly as
possible. The pedagogy is useful only if the peer evaluation is conducted seriously.

Guidelines
- Only grade the work that was turned in the Git repository of the evaluated
student or group.

- Verify that the Git repository belongs to the student(s) and that the
submitted project matches the expected one.
Additionally, ensure that 'git clone' is executed in an empty directory.

- Carefully verify that no malicious aliases were used to deceive you into
evaluating content that is not from the official repository.

- To avoid any surprises and if applicable, review together any scripts used
to facilitate the grading (scripts for testing or automation).

- If you have not completed the assignment yourself, you must read the entire
subject before starting the evaluation process.

- Use the available flags to report an empty repository, a non-functioning
program, a Norm error, cheating, and so forth.
In these cases, the evaluation process ends and the final grade is 0,
or -42 in case of cheating. However, except in cases of cheating,
students are strongly encouraged to review the submitted work together
to identify mistakes that should not be repeated in the future.

Attachments
 subject.pdf
 Preliminary tests
 If cheating is suspected, the evaluation stops here. Use the "Cheat" flag to report it. Make this decision calmly and wisely, and use this option with caution.

 Prerequisites

 Defense can only happen if the evaluated student or group is present. This way everybody learns by sharing knowledge.
 If no work has been submitted (or wrong files, wrong directory, or wrong filenames), the grade is 0, and the evaluation process ends.
 The repository must not be empty (i.e., it must contain relevant project files).
 No Norm error.
 Cheating (= -42).
 No compilation error. Also, the Makefile must not re-link.
 If all of these requirements are passed, check 'Yes' and continue the
 evaluation process. Otherwise, use the appropriate flag at the end of
 the scale!

 General instructions
 General instructions

 If a crash or unexpected error occurs (segmentation fault, bus error, nonsense display, and so forth), use the flag 'Crash'!
 The Makefile compiles the executable with the required options.
 The executable is named 'pipex'.
 No forbidden function is used.
 Mandatory part
 The command './pipex file1 cmd1 cmd2 file2' must behave like this command: '< file1 cmd1 | cmd2 > file2'

 Error and arguments management

 The program takes 4 arguments, no more, no less (except for bonus part) and only in the required order.
 Error handling must be correct and include the management of existing/non-existing files, file permissions, and missing or incorrect command binaries.
 If all these criteria are met, check 'Yes' and proceed with the evaluation.
 Otherwise, the evaluation is over. Use 'Incomplete work' or any other appropriate flag.

 The program

 The program must strictly follow the subject's requirements and should not
 display additional information or steps beyond what the shell command would.

 Run your own tests and compare the program results against the original
 shell output. Take a look at the subject examples if you need to.

 If no error happens, check 'Yes' and continue. Otherwise, the evaluation
 process ends now.

 Bonus part
 Evaluate the bonus part if, and only if, the mandatory part has been entirely and perfectly done, and the error management handles unexpected or bad usage. In case all the mandatory points were not passed during the defense, bonus points must be totally ignored.

 Multiple pipes

 The program manages the usage of several pipes one after another.
 As for the mandatory part, test with shell commands then compare with
 program output.

 If the program works with 2 pipes but fails with 5, the bonus is not awarded.

 << and >> with here_doc parameter

 The program replicates the use of << and >>.

 Test multiple times something like:
 'CMD << STOP_VALUE | CMD1 >> file1'


