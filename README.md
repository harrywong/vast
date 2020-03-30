![everiToken Logo](./docs/logo.png)

**World's First Token-customized Public Chain for the Token Economy and for Everyone.**
---
![Build Status](https://codebuild.us-east-2.amazonaws.com/badges?uuid=eyJlbmNyeXB0ZWREYXRhIjoiTFFYVEF1UDVXaVZrWGNUOVlKSnphcElOMFBzZUFjZ0QwZHpoNCtseVdFdTVoa3hHeWpOQ1ZzWk51bUVHTXlIRjk4Z1d4UFJrUmVyQ2xVaWhHSkxabURJPSIsIml2UGFyYW1ldGVyU3BlYyI6IkFIWFJNOHZsVjZGOThuVzQiLCJtYXRlcmlhbFNldFNlcmlhbCI6MX0%3D&branch=master)

Welcome to the everiToken source code repository!

everiToken public chain is developed and maintained by everiToken Team. The MainNet of everiToken has launched on 31st July 2018.

This code is under rapid development. If you have any questions or advices, feel free to open an issue.

## SDKs
If your need is to develop applications based on everiToken, `JavaScript SDK` is provided and maintained officially. It's suitable for the usage on web, backend and mobile platforms like Android and iOS.

* [JaveScript SDK](https://github.com/everitoken/vastjs)

## Resources
1. [everiToken Website](https://www.everitoken.io/)
2. [Technical Whitepaper](https://everitoken.io/docs/whitepaper.pdf)
3. [Developer Portal](https://everitoken.io/developers)

## Supported Operating Systems
everiToken currently supports the following operating systems:  
1. Amazon 2017.09 and higher
2. Centos 7
3. Fedora 25 and higher (Fedora 27 recommended)
4. Mint 18
5. Ubuntu 16.04 and higher (Ubuntu 18.04 recommended)
6. MacOS Darwin 10.12 and higher (MacOS 10.13.x recommended)

## 3rd-Party Projects by everiToken Community

**Note: Projects below are driven and maintained by the community, links are provided here only for convenience.**

1. [MyVAST Wallet](http://myvast.io)

## Getting Started

Please refer to [Developer Portal](https://www.everitoken.io/developers).

## For Production

The blockchain RPC interface is not designed for the Internet but for local network. And since RPC interface don't provide features like rate limitation's, security checks and so on. It highly suggests anyone who wants to run a node to use a reverse proxy server like nginx to serve all the requests.
