📌 Project Purpose & Scope
Purpose

This project aims to develop a command-line file system scanning utility written in C.

The tool recursively traverses a given directory and reports files that match user-defined criteria such as file extension, name pattern, size, and last modification time.

The primary goal of this project is not to build a full-featured file manager, but to gain hands-on experience with low-level system programming concepts, including direct interaction with the operating system, file system traversal, and memory management.

Scope

This tool is designed as a read-only utility.

It:

Recursively scans directories starting from a given path

Filters files based on configurable criteria

Outputs matching file paths in a script-friendly format

Continues execution gracefully when encountering permission or access errors

It does not:

Modify, delete, or create files

Read file contents

Provide a graphical user interface

Perform multithreaded scanning

Motivation

Modern systems rely heavily on small, efficient command-line tools that can be composed into larger workflows.

This project is intended to simulate such real-world utilities by focusing on:

Predictable behavior

Clear separation of responsibilities

Stability over feature complexity

The resulting program can be used as a standalone utility or integrated into automation scripts and build pipelines.

Target Audience

This tool is intended for:

Developers who need lightweight file system inspection tools

System programming learners seeking practical experience with POSIX APIs

Projects requiring custom file scanning logic (e.g., asset pipelines)

Design Principles

Single responsibility per module

Explicit and controlled memory ownership

Clear and consistent command-line interface

Minimal external dependencies

Portability across POSIX-compliant systems

🔍 Why This Project Exists

The value of this project lies in understanding how common system utilities work internally, rather than relying on existing tools such as find.

By implementing core functionality from scratch, the project emphasizes correctness, robustness, and maintainability.