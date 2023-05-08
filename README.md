<h1 align="center">
    <p>
        📓 FdF
    </p>
</h1>

<p align="center">
    <b><i>Repo for the FdF project at 42 Heilbronn</i></b>
</p>

<p align="center">
    This repository is coded in&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=c" />
    </a>
     &nbsp&nbspwith&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=neovim" />
    </a>
</p>

<h3 align="center">
    Status
</h3>

<p align="center">
    Finished: <br>
    Grade: %
</p>

---

## 💾 About
> The task of the minitalk project is to code 2 C programs that communicate with each other via only 2 Signals (SIGUSR1 & SIGUSR2).

## Usage
Minitalk has 2 programs that communicate with each other. The _server_ has to be started first in a separate terminal using `./server`
and then the _client_ can be used to send a message to the server. This can be done using the syntax: `./client PID "message"`
where PID is the process number that the server printed out on startup. After sending the message from the client, 
the server sends back an acknowledgment signal and the client prints out the acknowledged bytes.

```bash
git clone https://github.com/kurz-m/minitalk.git
```

```bash
cd minitalk
```
```bash
make
```
```bash
./server
```
```bash
./client <PID> "message"
```
