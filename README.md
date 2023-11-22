# popl_project
### 1) Problem Statement
   The Why is : C++ implementation of concurrent reading and writing might be outperformed by Rust according to certain web sources we referred , we did this project to set that in stone by doing proper testing.
   
   The What is : The end problem being addressed in the provided C++ and Rust code snippets is the concurrent reading of data from the "input.txt" file, storing it in memory, and subsequently writing the data to the "output.txt" file.
   
   The How is : Refer to 3) POPL Aspects and other implementation based information sprinkled throughout the ReadME

### 2) Software Architecture
   #### C++ Implementation:

1. Components:
   - Threads: Two threads (`reader_thread` and `writer_thread`) for reading from and writing to a file.
   - File Operations: Utilizes `<fstream>` for file input and output.
   - Data Structure: Uses a vector (`file_content`) to store lines read from the file.
   - Error Handling: Incorporates error handling for file-related operations.

2. Concurrency Model:
   - Basic multithreading with shared data (vector) among threads.

3. Reuse and Development:
   - Reuse: Standard C++ libraries (`<iostream>`, `<fstream>`, `<thread>`) for I/O and multithreading.
   - Development: Specific features and logic for file handling and multithreading.

#### Rust Implementation:

1. Components:
   - Threads: One thread for reading from a file and writing to another.
   - File Operations: Utilizes `std::fs` for file input and output.
   - Data Structure: Uses a vector (`lines`) to store lines read from the file.
   - Error Handling: Utilizes Rust's `expect` for handling potential errors.

2. **Concurrency Model:**
   - Leverages Rust's ownership system to ensure safe concurrent access to data.

3. Reuse and Development:
   - Reuse: Standard Rust libraries (`std::fs`, `std::thread`) for file operations and multithreading.
   - Development: Specific features and logic for ownership management and file operations.

### High-Level Architecture Figure:

```
+-----------------------+            +-----------------------+
|      Main Function    |          |     Main.rs Function |
|                       |                    |                                |
|  +-----------------+  |            |  +-----------------+  |
|  |    reader()     |  |            |  |   reader()     |  |
|  +-----------------+  |            |  +-----------------+  |
|  |    writer()     |  |            |  |   writer()     |  |
|  +-----------------+  |            |  +-----------------+  |
|  | file_content[]  |  |            |  |    lines[]     |  |
|  +-----------------+  |            |  +-----------------+  |
+-----------------------+            +-----------------------+
```

### Architecture Explanation:

- Both implementations follow a simple, standalone multithreading architecture without client-server interactions.
- The main functions orchestrate the creation and joining of threads.
- Data (lines read from the file) is shared among threads using vectors.
- Error handling is integrated into the file operations for robustness.


3) POPL Aspects
   
  ### C++ Implementation:

1. Thread Synchronization (Mutex):
   - POPL Angle: The use of threads (`reader_thread` and `writer_thread`) involves shared data access. To prevent data races, a mutex could be used to synchronize access to the shared `file_content`.
   - Solving Before: No explicit use of mutex in the provided code.
   - **Difference:** The current solution does not incorporate mutexes, and synchronization is done implicitly by joining the threads.

2. Error Handling:
   - POPL Angle: Proper error handling is included for file operations, such as opening and creating files.
   - Solving Before: The use of `ifstream` and `ofstream` for file operations, along with error messages, addresses potential issues during file access.
   - Difference: The provided solution adequately handles file-related errors, ensuring robustness.

### Rust Implementation:

1. Ownership and Concurrency Safety:
   - POPL Angle: Rust's ownership system ensures safe and concurrent access to data. The ownership model helps prevent data races and ensures memory safety.
   - Solving Before: The ownership system is explicitly utilized by cloning the vector to ensure that each thread owns its copy of the data.
   - Difference: Rust's ownership model is inherently embedded in the solution, providing a strong guarantee of safety in concurrent access.

2. Error Handling:
   - POPL Angle: Rust's emphasis on proper error handling is reflected in the use of `expect` for various file-related operations.
   - Solving Before: The `expect` method is used to handle potential errors during file operations.
   - Difference: Rust's approach to error handling is more explicit, encouraging developers to handle errors systematically.

### Overall Comparison:

- Both implementations demonstrate principles of concurrent programming and file I/O.
- The C++ implementation uses threads without explicit synchronization mechanisms, while the Rust implementation leverages ownership for concurrency safety.
- Error handling in file operations is addressed in both solutions, with Rust's approach being more explicit.

### Potential Enhancements:

- For a more comprehensive comparison, the C++ implementation could benefit from incorporating explicit synchronization mechanisms, such as mutexes, to address potential data race scenarios.
- Both implementations could further explore parallelism and performance improvements, such as asynchronous file I/O or parallel data processing.

In summary, the POPL aspects in both implementations revolve around concurrent access to shared data and proper error handling. The Rust solution highlights its ownership system for enhanced safety, while the C++ solution could be strengthened by incorporating explicit synchronization mechanisms.

### 4) RESULTS 
  The testing is done informally using libraries present in the respective languages to calculate time for execution of a particular program. We did three tests each for a given input and took the average time.

  We did testing for read performance and write perfromance separately to give more insightful results.
  
  The following are some graphs which show our outputs:

   ![WhatsApp Image 2023-11-22 at 20 35 48_299fcd24](https://github.com/Srujal194/popl_project/assets/102753313/9bfdbf1d-9703-4112-ad85-7f35dc0fafaa)
   ![WhatsApp Image 2023-11-22 at 20 36 02_b4ee83ea](https://github.com/Srujal194/popl_project/assets/102753313/8c735a8e-223a-4f5a-84d4-9cefe36b3612)















   ### Convincing Points:

- Performance Improvements: Clear evidence of improved performance in Rust over C++ for multithreaded operations based on the benchmarks and tests conducted.

- Consistency and Reliability: Consistent results across multiple runs and scenarios, providing confidence in the reliability of your implementation.

- Visualization: Graphical representations that vividly illustrate the performance differences between C++ and Rust can be compelling.

- Comparison with Previous Studies: If your results align with existing studies or benchmarks, it adds credibility to your findings.

- Code Complexity Metrics: Demonstrating that Rust's advantages in terms of safety and performance come with reasonable or even reduced implementation complexity.

By rigorously conducting and presenting these tests, you can build a data-driven case to convince stakeholders that your solution effectively addresses the challenges outlined in the initial problem statement.
### 5) Potential for future works


1. Advanced Concurrency Models:
Objective: Further exploration of advanced concurrency models and paradigms in Rust, such as actor-based concurrency or data parallelism, to assess their applicability and benefits in the context of multithreaded file operations.
Rationale: This extension aims to investigate alternative concurrency models beyond the traditional multithreading approach. Actor-based concurrency, for instance, can provide a message-passing paradigm that may enhance modularity and scalability in certain scenarios. Similarly, exploring data parallelism can leverage Rust's features for parallelizing operations on large datasets.
2. Fine-Grained Performance Analysis:
Objective: Conducting a detailed performance analysis to gain insights into the fine-grained aspects of multithreading in both Rust and C++, utilizing profiling tools for bottleneck identification, critical section optimization, and overall performance fine-tuning.
Rationale: While high-level performance metrics provide valuable insights, a fine-grained analysis allows for a more nuanced understanding of the system's behavior. Profiling tools can pinpoint specific areas where optimizations can be applied, leading to targeted improvements in the efficiency of multithreaded file operations.
3. Transaction and Rollback Mechanisms:
Objective: Investigating transactional mechanisms for file operations in both Rust and C++, with a focus on how Rust's ownership system can facilitate transactional semantics. Comparing this with transactional models in C++, considering aspects of atomicity and consistency in file operations.
Rationale: Transactional mechanisms enhance the robustness of file operations by ensuring atomicity and consistency. Rust's ownership system, with its emphasis on preventing data races, may offer a unique approach to implementing transactional semantics. Comparing this with transactional models in C++ provides insights into how language features influence the implementation of such mechanisms.
4. Formal Verification Techniques:
Objective: Integrating formal verification techniques to ensure correctness and safety in multithreaded file operations. This involves applying methods like model checking or theorem proving to provide mathematical guarantees regarding the absence of data races or other concurrency-related issues.
Rationale: Formal verification adds an additional layer of assurance by mathematically proving the correctness of the implemented multithreaded file operations. This approach aligns with the principles of POPL, ensuring that the concurrent code adheres to specified properties without relying solely on testing. It contributes to the development of highly reliable and secure systems.
By addressing these aspects in detail, the project can extend its scope to encompass a broader range of concurrency-related considerations, pushing the boundaries of understanding and implementation in the context of multithreaded file operations in Rust and C++.


### WORK DISTRIBUTION
It was a collaborative effort with everyone chipping in sometime from their busy schedules.
