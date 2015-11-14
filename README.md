# SC15_Examples
Examples for the SC15 Tutorial on HPX

- Run bash:

  ```
  $ bash
  $ source /usr/share/Modules/init/bash
  ```

- In order to work on the Examples, you first need to load the HPX Tutorial environment:

  ```
  $ . /project/projectdirs/training/SC15/HPX-SC15/hpx_install/env.sh
  ```
- This will allow you to load the HPX module files
  
  - On Babbage, for the host:

  ```
  $ module load hpx/host-0.9.11-release
  ```
  - On Babbage, for the mic:

  ```
  $ module load hpx/mic-0.9.11-release
  ```
  - On Edison:

  ```
  $ module load hpx/0.9.11-release
  ```
- Build an example (for example hello_world):

  ```
  $ mkdir build; cd build
  $ hpxcmake /path/to/examples/00_hello_world
  $ make -j8
  ```
- Run the example:
  - Babbage:
  
  ```
  $ srun -n2 -N2 --pty mpirun ./hello_world
  ```
  - Edison:
  
  ```
  $ qsub -I -l mppwidth=48
  $ aprun -n2 -N1 -d 24 -cc none ./hello_world
  ```
