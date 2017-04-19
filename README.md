# Simple FTP

## Usage
1. `./siftpd [folder] [port]` to create a server with defined port. This might require permissions, give it.
2. `./siftp [port]` establish a connection to server. default username and password `ict58`

## List commands
1. `ls` displays contents of remote current working directory.
2. `lls` displays contents of local current working directory
3. `pwd` displays path of remote current working directory.
4. `lpwd` displays path of local current working directory.
5. `cd <path>` changes the remote current working directory to the specified <path>.
6. `lcd <path>` changes the local current working directory to the specified <path>.
7. `get <src> [dest]` downloads the remote <src> to local current working directory by the name of [dest] if specified.
8. `put <src> [dest]` uploads the local <src> file to remote current working directory by the name of [dest] if specified.
9. `help` displays this message.
10. `exit` terminates this program.
