# SC15_Examples (Tutorial Instructions for Edison)

Examples for the SC15 Tutorial on HPX

- First, let's get everyone logged onto Edison.

- Next, we'll download the Examples from github:

  ```
  git clone https://github.com/STEllAR-GROUP/SC15_Examples.git  
  cd SC15_Examples
  ```

- In order to work on the Examples, you first need to load the HPX Tutorial environment and load the HPX module files:

  ```
  . /project/projectdirs/training/SC15/HPX-SC15/hpx_install/env.sh
  module load hpx/0.9.11-release
  ```

- Build an example (for example hello_world):

  ```
  mkdir build_hello_world; cd build_hello_world
  hpxcmake ../00_hello_world
  make -j4
  ```

- Now, you'll each need an interactive session:

  ```
  qsub -I -l mppwidth=48 -W x=FLAGS:ADVRES:Edison.SC15.376253
  ```

- Run the example:
  
  ```
  . /project/projectdirs/training/SC15/HPX-SC15/hpx_install/env.sh
  module load hpx/0.9.11-release
  cd ~/SC15_Examples/build_hello_world
  aprun -n2 -N1 -d 24 -cc none ./hello_world
  ```

