# Detailed Design

## Riley Persily, Andrew Arteaga, Simon Wroblewski

### 2.1 - Detailed list of Linux modules that will be modified/affected

The `top` module will be modified for our project.  We will not affect the original `top` module but rather take the module, modify it, and reinsert to create our `rearrange` module.  

### 2.2 - Detailed list of any new modules that you will produce [or 'Not Applicable' if there are none]

The module `rearrange` will be a new module added to our kernel. It's functionality can be described as a command that will allow you to "rearrange" the priority of a process.

### 2.3 - Class diagram showing affected modules [and any new modules] and how they related to one another

### 2.4 - List or table of explanations of all command line options that will be implemented

* `rearrange` - Base command

* `-t [pid]` - Sets the process with the given Process ID to have the top priority

* `-b [pid]` - Sets the process with the given Process ID to have the bottom priority

* `-s [pid] [priority #]` - Sets the process with the given Process ID to the given spot in the priority order