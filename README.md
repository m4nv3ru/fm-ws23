# Forschungsmethoden 2023 Benchmarking

## Prerequisites

Before initiating the benchmarking framework, certain requirements must be fulfilled:
- Ensure that g++ is available by running the command `sudo apt install g++`
- Ensure that javac is available by running the command `sudo apt install openjdk-17-jdk-headless`
- Ensure Python 3.10 is available by running the command `sudo apt install python3.10`
- Ensure Python 3.10 virtual environment is available by running the command with `sudo apt install python3.10-venv`

## Set up
The benchmarking framework includes a `setup_venv.sh` script that initializes a Python virtual environment and installs all necessary dependencies. 
Additionally, a `launch.sh` script is provided for starting the Jupyter server, which facilitates the execution of benchmark tests.
For each programming language that has an implementation of merge sort, there are two key files:
- The source file containing the implementation.
- A makefile that offers various utility functions.

```
├── PROGRAMMING_LANGUAGE
│   ├── source_code.extension
│   └── Makefile
├── launch.sh
├── setup_venv.sh
├── fm.ipynb
```

### Makefile
To streamline the process of compiling and executing programs written in various languages, Makefiles can be utilized with the following structure:

```
compile:
	@echo "Compiling your program..."
	# Add the command to compile your program here

clean:
	@echo "Cleaning up files created during compilation..."
	# Add the command to clean up files here

run:
	@echo "Executing your program..."
	# Add the command to execute your program here, for example:
	# ./your_program ../problem_size.txt

run-result:
	@echo "Executing your program and showing results..."
	# Add the command to execute your program and show results here, for example:
	# ./your_program ../problem_size.txt true

compile-run: 
	$(MAKE) compile
	$(MAKE) run
```

In this Makefile:
- The `compile` target includes a placeholder for the actual compile command.
- The `clean` target should contain commands to remove files generated during compilation.
- The `run` and `run-result` targets are for executing the program, with the latter writing the results into a file.
- The `compile-run` target first compiles and then runs the program.