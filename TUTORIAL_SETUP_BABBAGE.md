# SC15_Examples (Tutorial Instructions for Babbage)

Examples for the SC15 Tutorial on HPX

- First, let's get everyone logged onto Babbage.

- Now, you'll each need an interactive session:

  ```
  salloc -N 2 -t 02:00:00 --reservation=SC_Reservation -p regular
  ```

- Switch to bash:

  ```
  bash
  source /usr/share/Modules/init/bash
  ```

- Next, we'll download the Examples from github:

  ```
  git clone https://github.com/STEllAR-GROUP/SC15_Examples.git  
  cd SC15_Examples
  ```

- In order to work on the Examples, you first need to load the HPX Tutorial environment and load the HPX module files:

  ```
  . /project/projectdirs/training/SC15/HPX-SC15/hpx_install/env.sh
  module load hpx/host-0.9.11-release
  ```

- Build an example (for example hello_world):

  ```
  mkdir build_hello_world; cd build_hello_world
  hpxcmake ../00_hello_world
  make -j4
  ```

- Run the example:
  
  ```
  get_hostfile && mpirun.host -n 1 -hostfile hostfile.$SLURM_JOB_ID -ppn 1 ./hello_world -t16 
  ```


