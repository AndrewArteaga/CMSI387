# Preliminary Design
#### Riley Persily, Andrew Arteaga, Simon Wroblewski
## 1.1
The addition to Linux will provide the ability to use a command and receive a list of the current priorities, much like the `top` command, but will add the ability to reorder the priorities of each process as desired.  Users will be able to select a process by entering the process ID and choosing a new place in the list of priority.  There could be quick commands `toTop` and `toBottom` used to automatically send processes to the top or bottom of the priority order.
## 1.2
This addition will be useful as it will allow users to expand their control of the system by assigning higher/lower priority to whichever processes they choose.  Users can already view the priority of processes which gives insight, but not control.  Adding the ability to rearrange priorities gives the users total control over what their machine is providing the most processing power to.
## 1.3
May affect and/or implement ‘top’ command/module since it already returns a list of processes in descending order of priority. Until we implement the changes to the kernel we won't know the extent of the affected modules.
## 1.4
Will add the `rearrange` module.
