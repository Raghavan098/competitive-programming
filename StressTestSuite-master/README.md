# StressTestSuite
A collection of scripts to generate common competitive programming testcases on Linux.

# How to use

1. `gen.py` : Use this to generate random testcases by invoking the various functions provided
2. `test.sh` : This shell scripts creates a random testcase, runs two exectuables simultaneously on the random testcase and checks if the outputs match. It repeats this for 10,000 random test cases.
3. `check.py` : Script used by `test.sh` to check if outputs of the two executable programs match.

# What is Stress Testing?

Have you ever been in sitauation where you have written a state-of-the-art algorithm for some task but it your code is generating incorrect output? If yes, have you ever felt lazy to manually generate test cases to detect the bug in your code? Well stress testing solves this very problem. The idea is that instead of generating test cases manually, you write a simple brute force solution that solves the same problem that you are trying to solve with your state-of-the-art algorithm and then leave it to your computer to randomly generate test cases till the ouptuts of both programs don't match.
