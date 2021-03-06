# OSExercise
	2018级操作系统设计	
 
实习一  处理器调度
一、实习内容
选择一个调度算法，实现处理器调度。
二、实习目的
本实习模拟在单处理器环境下的处理器调度，加深了解处理器调度的工作。
三、实习题目
本实习有两题，可任选一题。
第一题：设计一个按优先数调度算法实现处理器调度的程序。
[提示]：
(1)假定系统有5个进程，每个进程用一个PCB来代表。PCB的结构为：
·进程名——如P1~P5。
·指针——按优先数的大小把5个进程连成队列，用指针指出下一个进程PCB的首地址。
·要求运行时间——假设进程需要运行的单位时间数。
·优先数——赋予进程的优先数，调度时总是选取优先数大的进程先执行。
·状态——假设两种状态：就绪和结束，用R表示就绪，用E表示结束。初始状态都为就绪状态。
(2) 开始运行之前，为每个进程确定它的“优先数”和“要求运行时间”。通过键盘输入这些参数。
(3) 处理器总是选择队首进程运行。采用动态改变优先数的办法，进程每运行1次，优先数减1，要求运行时间减1。
(4) 进程运行一次后，若要求运行时间不等于0，则将它加入就绪队列，否则，将状态改为“结束”，退出就绪队列。
(5) 若就绪队列为空，结束，否则转到(3)重复。
要求能接受键盘输入的进程优先数及要求运行时间，能显示每次进程调度的情况，如哪个进程在运行，哪些进程就绪，就绪进程的排列情况。

第二题：设计一个按时间片轮转法实现处理器调度的程序
[提示]：
（1）假定系统有5个进程，每个进程用一个PCB来代表。PCB的结构为：
·进程名——如Q1~Q5。
·指针——把5个进程连成队列，用指针指出下一个进程PCB的首地址。
·要求运行时间——假设进程需要运行的时间单位数。
·已运行时间——进程已运行的时间单位数，初始值为0。
·状态——假设两种状态，就绪和结束，用R表示就绪，用E表示结束。初始状态都为就绪状态。
(2) 运行之前，为每个进程确定它的“要求运行时间”。通过键盘输入这些参数。
(3) 把5个进程按顺序排成循环队列，用指针指出队列连接情况。用一个标志单元记录轮到运行的进程。处理器调度总是选择标志单元指示的进程运行，对所指的进程，将其“已运行时间”加1。
(4) 进程运行一次后，若“要求运行时间”等于“已运行时间”，则将状态改为“结束”，退出队列，否则将继续轮转。
(5) 若就绪队列为空，结束，否则转到(3)重复。
要求能接受键盘输入的进程要求运行时间，能显示每次进程调度的情况，如哪个进程在运行，哪些进程就绪。

实习二  主存空间的分配和回收
一、实习内容
主存储器空间的分配和回收。
二、实习目的
通过本实习帮助理解在不同的存储管理方式下应怎样进行存储空间的分配和回收。
三、实习题目
本实习有两题，可任选一题。

第一题：可变分区管理方式下采用首次适应算法实现主存分配和回收
[提示]：
(1)	可变分区方式是按作业需要的主存空间大小来分割分区的。当要装入一个作业时，根据作业需要的主存容量查看是否有足够的空闲空间，若有，则按需分配，否则，作业无法装入。假定内存大小为128K，空闲区说明表格式为：
·分区号——表示是第几个空闲分区；
·起始地址——指出空闲区的起始地址；
·长度——一个连续空闲区的长度；
(2)	采用首次适应算法分配回收内存空间。运行时，输入一系列分配请求和回收请求。
要求能接受来自键盘的空间申请及释放请求，能显示分区分配及回收后的内存布局情况。

第二题：在分页管理方式下采用位示图来表示主存分配情况，实现主存分配和回收
[提示]：
(1)	假定系统的主存被分成大小相等的64个块，用0/1对应空闲/占用。
(2)	当要装入一个作业时，根据作业对主存的需求量，先查空闲块数是否能满足作业要求，若能满足，则查位示图，修改位示图和空闲块数。位置与块号的对应关系为：
块号=j*8+i，其中i表示位，j表示字节。
根据分配的块号建立页表。页表包括两项：页号和块号。
(3)	回收时，修改位示图和空闲块数。
要求能接受来自键盘的空间申请及释放请求，能显示位示图和空闲块数的变化，能显示进程的页表。


实习三  磁盘存储空间的分配和回收

一、实习内容
模拟磁盘空闲空间的表示方法，以及模拟实现磁盘空间的分配和回收。
二、实习目的
磁盘初始化时把磁盘存储空间分成许多块（扇区），这些空间可以被多个用户共享。用户作业在执行期间常常要在磁盘上建立文件或把已经建立在磁盘上的文件删去，这就涉及到磁盘存储空间的分配和回收。一个文件存放到磁盘上，可以组织成顺序文件（连续文件）、链接文件（串联文件）、索引文件等，因此，磁盘存储空间的分配有两种方式，一种是分配连续的存储空间，另一种是可以分配不连续的存储空间。怎样有效地管理磁盘存储空间是操作系统应解决的一个重要问题，通过本实习使学生掌握磁盘存储空间的分配和回收算法。
三、实习题目
本实习有三个题目，可以任选一个，但不能与内存管理的题目类似。
第一题：连续磁盘存储空间的分配和回收
[提示]：
(1) 要在磁盘上建立顺序文件时，必须把按序排列的逻辑记录依次存放在磁盘的连续存储空间中。可假定磁盘初始化时，已把磁盘存储空间划分成若干等长的块（扇区），按柱面号和盘面号的顺序给每一块确定一个编号。随着文件的建立、删除、磁盘存储空间被分成许多区（每一区包含若干块），有的区存放着文件，而有的区是空闲的。当要建立顺序文件时必须找到一个合适的空闲区来存放文件记录，当一个文件被删除时，则该文件占用的区应成为空闲区。为此可用一张空闲区表来记录磁盘存储空间中尚未占用的部分，格式如下：

序  号	起始空闲块号	空闲块个数	状    态
1	5	6	未 分 配
2	14	3	未 分 配
3	21	30	未 分 配
4			
。。。			


(2) 建立文件时，先查找空闲区表，从空闲区表中找出一个块数能满足要求的区，由起始空闲块号能依次推得可使用的其它块号。若不需要占用该区的所有块时，则剩余的块仍应为未分配的空闲块，这时要修改起始空闲块号和空闲块数。若占用了该区的所有块，则删去该空闲区。删除一个文件时，需要考虑空闲块的合并情况。
磁盘存储空间的分配和回收算法类似于主存储器的可变分区方式的分配和回收。同学们可参考实习二的第一题。
(3) 当找到空闲块后，必须启动磁盘把信息存放到指定的块中，启动磁盘必须给出由三个参数组成的物理地址：盘面号、柱面号和物理记录号（即扇区号）。故必须把找到的空闲块号换算成磁盘的物理地址。
为了减少移臂次数，磁盘上的信息按柱面上各磁道顺序存放。现假定一个盘组共有200个柱面，（编号0-199）每个柱面有20个磁道（编号0-19，同一柱面上的各磁道分布在各盘面上，故磁道号即盘面号。），每个磁道被分成等长的6个物理记录（编号0-5，每个盘面被分成若干个扇区，故每个磁道上的物理记录号即为对应的扇区号）。那么，空闲块号与磁盘物理地址的对应关系如下：
则  物理记录号 = 空闲块号 % 6
磁道号=（空闲块号 / 6 ）% 20 
柱面号=（空闲块号 / 6）/20

(4) 删除一个文件时，从文件目录表中可得到该文件在磁盘上的起始地址和逻辑记录个数，假定每个逻辑记录占磁盘上的一块，则可推算出归还后的起始空闲块号和块数，登记到空闲区表中。换算关系如下：
起始空闲块号=（柱面号20+磁道号）6+物理记录号
空闲块数=逻辑记录数
(5) 请设计磁盘存储空间的分配和回收程序，要求把分配到的空闲块转换成磁盘物理地址，把归还的磁盘空间转换成空闲块号。
要求能接受来自键盘的空间申请及释放请求，能显示或打印分配及回收后的空闲区表以及分配到的磁盘空间的起始物理地址：包括柱面号、磁道号、物理记录号（扇区号）。

第二题：用位示图管理磁盘存储空间
[提示]：
(1) 为了提高磁盘存储空间的利用率，可在磁盘上组织成链接文件、索引文件，这类文件可以把逻辑记录存放在不连续的存储空间。为了表示哪些磁盘空间已被占用，哪些磁盘空间是空闲的，可用位示图来指出。位示图由若干字节构成，每一位与磁盘上的一块对应，“1”状态表示相应块已占用，“0”状态表示该块为空闲。位示图的形式与实习二中的位示图一样，但要注意，对于主存储空间和磁盘存储空间应该用不同的位示图来管理，绝不可混用。
(2) 申请一块磁盘空间时，由分配程序查位示图，找出一个为“0”的位，计算出这一位对应块的磁盘物理地址，且把该位置成占用状态“1”。假设现在有一个盘组共8个柱面，每个柱面有2个磁道（盘面），每个磁道分成4个物理记录。那么，当在位示图中找到某一字节的某一位为“0”时，这个空闲块对应的磁盘物理地址为：
柱面号=字节号
磁道号= 位数 / 4
物理记录号= 位数 % 4
(3) 归还一块磁盘空间时，由回收程序根据归还的磁盘物理地址计算出归还块在位示图中的对应位，把该位置成“0”。按照（2）中假设的盘组，归还块在位示图中的位置计算如下：
字节号=柱面号
位数=磁道号4+物理记录号
(4) 设计申请磁盘空间和归还磁盘空间的程序。
要求能接受来自键盘的空间申请及释放请求，要求能显示或打印程序运行前和运行后的位示图；分配时把分配到的磁盘空间的物理地址显示或打印出来，归还时把归还块对应于位示图的字节号和位数显示或打印出来。

第三题：模拟UNIX系统的空闲块成组链接法，实现磁盘存储空间的管理
[提示]：
(1) 假定磁盘存储空间已被划分成长度为n的等长块，共有M块可供使用。UNIX系统中采用空闲块成组链接的方法来管理磁盘存储空间，将磁盘中的每N个空闲块（N<M）分成一组，最后一组可以不足N块，每组的第一块中登记了下一组空闲块的块数和块号，第一组的块数和块号登记在专用块中，登记的格式如下：

0	空闲块数k
1	空闲块号1
2	空闲块号2
…	…
K	空闲块号k
	

当第一项内容为“0”时，则第二项起指出的空闲块是最后一组。
（2）可用二维数组A [0…M-1] [0…n-1]来模拟管理磁盘空间，用A[i]表示第I块，第0块A[0]作为专用块。
(3) 成组链接的分组情况记录在磁盘物理块中，为了查找链接情况，必须把它们读入主存，故当磁盘初始化后，系统先将专用块内容复制到主存中。定义一个数组MA存放专用块内容，即MA: =A[0]。申请一块磁盘空间时，查MA，从中找出空闲块号，当一组的空闲块只剩第一块时，则应把该块中指出的下一组的空闲块数和块号复制到专用块中，然后把该块分配给申请者。当一组的空闲块分配完后则把专用块内容（下一组链接情况）复制到主存，再为申请者分配。
 (4) 归还一块时给出归还的块号，若当前组不满规定块数时，将归还块登记入该组；若当前组已满，则另建一新组，这时归还块作为新一组的第一块，应把主存中登记的一组链接情况MA复制到归还块中，然后在MA重新登记一个新组。
(5) 设计分配和归还磁盘空间的程序。
要求能接受来自键盘的空间申请及释放请求，能显示或打印分配的磁盘空间的块号，在完成一次分配或归还后能显示或打印各空闲块组的情况（各组的空闲块数和块号）。本实习省去了块号与物理地址之间的转换工作，而在实际的系统中必须进行块号与物理地址的转换工作。


实习四  进程创建
一、实习内容
利用fork()系统调用创建进程。
二、实习目的
了解进程的创建过程，进一步理解进程的概念，明确进程和程序的区别。
三、实习题目
编制一段程序，使用系统调用fork( )创建两个子进程，这样在此程序运行时，在系统中就有一个父进程和两个子进程在活动。每一个进程在屏幕上显示一个字符，其中父进程显示字符A，子进程分别显示字符 B和字符C。试观察、记录并分析屏幕上进程调度的情况。
[提示]：
（1）可用fork()系统调用来创建一个新进程。
系统调用格式：pid=fork()
fork()返回值意义如下：
=0：若返回值为0，表示当前进程是子进程。
>0：若返回值大于0，表示当前进程是父进程，返回值为子进程的pid值。
-1：若返回值小于0，表示进程创建失败。
如果fork()调用成功，它向父进程返回子进程的pid，并向子进程返回0，即fork()被调用了一次，但返回了两次。此时OS在内存中建立一个新进程，所建的新进程是调用fork()父进程的副本，称为子进程。子进程继承了父进程的许多特性，并具有与父进程完全相同的用户级上下文。父进程与子进程并发执行。
（2）编译和执行的方法：
gcc  源文件名 -o 执行文件名
最后，在shell提示符下输入：   ./执行文件名   
 就可执行该文件。


实习五 进程同步
 一、实习内容
模拟实现同步机构，以避免发生进程执行时可能出现的与时间有关的错误。
二、实习目的
当进程并发执行时，如果对进程访问的共享变量不加限制，就会产生“与时间有关”的错误。为了防止这类错误，系统必须用同步机构来控制进程对共享变量的访问。
一般说，同步机构是由若干条同步原语所组成。本实验要求学生模拟P、V操作同步机构的实现，模拟进程的并发执行，了解进程并发执行时同步机构的作用。
三、实习题目
模拟P、V操作实现同步机构，且用P、V操作解决生产者—消费者问题。
[提示]：
(1) P、V操作同步机构，由P操作原语和V操作原语组成，它们的定义如下：
P操作原语P (s)：将信号量s减去1，若结果小于0，则执行原语的进程被置成等待信号量s的状态。
V操作原语V (s)：将信号量s加1，若结果不大于0，则释放一个等待信号量s的进程。
这两条原语是如下的两个过程：
procedure  p (var  s:  semaphore);
begin  s:  = s-1;
       if s<0 then W (s)
end  {p}
procedure  v (var  s:  semaphore);
begin  s:  = s+1;
      if s£0 then R (s)
end {v}
其中W（s）表示将调用过程的进程置为等待信号量s的状态；R（s）表示释放一个等待信号量s的进程。
在系统初始化时应把semaphore定义为某个类型，为简单起见，在模拟实验中可把上述的semaphore直接改成integer。
(2) 生产者—消费者问题。
假定有一个生产者和一个消费者，生产者每次生产一件产品，并把生产的产品存入共享缓冲器以供消费者取走使用。消费者每次从缓冲器内取出一件产品去消费。禁止生产者将产品放入已满的缓冲器内，禁止消费者从空缓冲器内取产品。假定缓冲器内可同时存放10件产品，用P、V操作来实现生产者和消费者之间的同步，生产者和消费者两个进程的程序如下：
B: array [0..9] of products;
s1, s2; semaphore;
s1: =10, s2: =0;
IN, out: integer;
IN: =0; out: =0;
cobegin
    procedure producer;
    c: products;
    begin
L1:
    Produce (c);
    P (s1);
    B[IN]: =C;
    IN: =(IN+1)mod 10;
    V (s2);
    goto L1
    end;
    procedure consumer;
    x: products;
    begin 
L2:  p (s2);
       x: =B[out];
       out: =(out+1) mod10;
       v (s1);
       consume (x);
       goto L2
    end;
coend.
其中的semaphore和products是预先定义的两个类型，在模拟实现中semaphore用integer代替，products可用integer或char等代替。
(3) 进程控制块PCB。
为了记录进程执行时的情况，以及进程让出处理器后的状态，断点等信息，每个进程都有一个进程控制块PCB。在模拟实验中，假设进程控制块的结构如图1。其中进程的状态有：运行态、就绪态、等待态和完成态。当进程处于等待态时，在进程控制块PCB中要说明进程等待原因（在模拟实验中进程等待原因是为等待信号量s1或s2）；当进程处于等待态或就绪态时，PCB中保留了断点信息，一旦进程再度占有处理器则从断点位置继续运行；当进程处于完成状态，表示进程执行结束。 
进程名
状态
等待原因
断点
图1  进程控制块结构
 (4) 处理器的模拟。
计算机硬件提供了一组机器指令，处理器的主要职责是解释执行机器指令。为了模拟生产者和消费者进程的并发执行，我们必须模拟一组指令和处理职能。
模拟的一组指令见图2，其中每条指令的功能由一个过程来实现。用变量PC来模拟“指令计数器”，假设模拟的指令长度为1，每执行一条模拟指令后，PC加1，提取出下一条指令地址。使用模拟的指令，可把生产者和消费者进程的程序表示为图3的形式。
定义两个一维数组PA[0..4]和SA[0..4]，每一个PA[i]存放生产者程序中的一条模拟指令执行的入口地址；每个SA[i]存放消费者程序中的一条模拟指令执行的入口地址。于是模拟处理器执行一条指令的过程为：取出PC之值，按PA[PC]或SA[PC]得模拟指令执行的入口地址，将PC之值加1，转向由入口地址确定的相应的过程执行。
(5) 程序设计
本实验中的程序由三部分组成：初始化程序、处理器调度程序、模拟处理器指令执行程序。各部分程序的功能及相互间的关系由图4至图7给出。
 
模拟的指令	功    能
p (s)	执行P操作原语
v (s)	执行V操作原语
Put	B[IN]: =product;  IN: = (IN+1) mod 10
GET	 x:=B[out];  out: =(out+1) mod 10
produce	输入一个字符放入C中
consume	打印或显示x中的字符
GOTO L	PC: =L
NOP	空操作
图2  模拟的处理器指令
 
序号	生产者程序	消费者程序
0	produce	p (s2)
1	p (s1)	GET
2	PUT	v (s1)
3	v (s2)	consume
4	goto 0	goto 0
图3  生产者和消费者程序
 ·初始化程序：模拟实验的程序从初始化程序入口启动，初始化工作包括对信号量s1、s2赋初值，对生产者、消费者进程的PCB初始化。初始化后转向处理调度程序，其流程如图4。



图4  初始化流程

·处理器调度程序：在计算机系统中，进程并发执行时，任一进程占用处理器执行完一条指令后就有可能被打断而让出处理器由其它进程运行。故在模拟系统中也类似处理，每当执行一条模拟的指令后，保护当前进程的现场，让它成为非运行态，由处理器调度程序按随机数再选择一个就绪进程占用处理器运行。处理器调度程序流程见图5。




图5  模拟处理器调度
·模拟处理器指令执行程序：按“指令计数器”PC之值执行指定的指令，且PC加1指向下一条指令。模拟处理器指令执行程序的流程图见图6和图7。
 图6  模拟处理器指令执行
  (a) 模拟P (s)                (b) 模拟V (s)
图7  模拟P、V操作的执行
 另外，为了使得模拟程序有一个结束条件，在图6中附加了“生产者运行结束”的条件判断，模拟时可以采用人工选择的方法实现。7给出了P（s）和V（s）模拟指令执行过程的流程。其它模拟指令的执行过程已在图2中指出。
