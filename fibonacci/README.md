<h1>FIBYNACHO</h1>

<h2>This folder contains two (WIP on 3) versions of my (super awesome epic) fibonacci algorithm.</h2>

The first version, manyFib, will print the entire sequence up to the number requested.
For example, giving an input of 5 will print the following:
<ul>
<li>Fib(0) = 0</li>
<li>Fib(1) = 1</li>
<li>Fib(2) = 1</li>
<li>Fib(3) = 2</li>
<li>Fib(4) = 3</li>
<li>Fib(5) = 5</li>
</ul>

<p>The generated file name will always be "FibbyG.txt" (TODO: Accept filename as command line argument)</p>

The second version, singleFib, will print only the number requested.
For example, giving and input of 5 will print the following:
Fib(5) = 5
The file name will also contain the number generated. For 5, the file name will be:
Fib(5).txt

For both versions, click the run.bat or type "start run.bat" into the command line. The results will be printed in the output folder.

If you are using manyFib, any time you run the program it will overwrite any file named "FibbyG.txt" will be overwritten so rename or move the output if you want to keep it.

If you want to make changes to my code and you have gcc installed, you can run the "comp.bat" script which will automatically compile both main.c and helper.c into a single exe.

<h3>----WIP----</h3>
My last version is called multiFib. It is a modified version of singleFib which utilises multithreading. It works exactly in the same way. 
