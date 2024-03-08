# minitalk
Communication between a server and a client.

I created server and client which can cummunicate with each other only using UNIX signals (SIGUSR1 and SIGUSR2).  

Following criteria had to be implemented:  

• The server must be started first. After its launch, it has to print its PID.  
• The client takes two parameters:  
&ensp;◦ The server PID.  
&ensp;◦ The string to send.  
• The client must send the string passed as a parameter to the server.  
&ensp;Once the string has been received, the server must print it.  
• Your server should be able to receive strings from several clients in a row without  
&ensp;needing to restart.  
• The communication between your client and your server has to be done only using  
&ensp;UNIX signals.  
• You can only use these two signals: SIGUSR1 and SIGUSR2.  

![push_swap](https://github.com/cyberKev42/minitalk/blob/main/minitalk.gif)
