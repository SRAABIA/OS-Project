# <h1 align="center">OS PROJECT Parallel Programming Comparison of Algorithms using Pthreads vs. OpenMP vs. serial</h1>
<h4 align="center">Sorting algorithms, as the name suggests, are used to sort data. OpenMP is a parallel programming library based on Symmetric Multi-processors, or shared-memory processors model. When using OpenMP, all memory and data is shared through threads. Due to openMP we can write the more efficient and lower-level parallel code due to openMP using threads, which are basic units of processing greatly increasing speed of a singular function. Pthreads are manually written and designed for parallel programming while this will be easier when done using OpenMP. Serial sorting will be using simple processes to execute the respective functions of a single sort. Our project will demonstrate the differences between crudely using processes and using threads using OpenMP.</h4>

<h3 align="center">3 Sorting Algorithms</h3>
<p align="center">
- Binomial Series
- Taylor Series
- Interpolation Search
</p>

## <h3 align="left">OpenMP</h3>
#### <p align="left"> Among the parallelization techniques, OpenMP consistently demonstrated the most efficient execution time across all three algorithms. Its ability to distribute the workload among multiple threads effectively improved the overall performance, resulting in the shortest execution times. This highlights the advantages of utilizing OpenMP for parallelizing algorithms in an operating system context. </p>

## <h3 align="left">Pthread</h3>
#### <p align="left"> On the other hand, the pthread implementation, while still introducing parallelism, exhibited relatively higher execution times compared to OpenMP. However, it provided a noticeable improvement over the serial implementation, indicating the benefits of multithreading and concurrent execution.</p>
## <h3 align="left">Serial</h3>
#### <p align="left"> The serial implementation, without any parallelization, consistently displayed the longest execution times. This outcome emphasizes the importance of parallelizing algorithms, especially in resource-intensive tasks like those encountered in operating system courses.</p>

## <h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> </p>
