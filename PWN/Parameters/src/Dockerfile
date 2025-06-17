FROM i386/debian:bullseye
RUN apt update && apt install -y build-essential gcc-multilib socat && rm -rf /var/lib/apt/lists/*
RUN useradd -m ctfuser
WORKDIR /home/ctfuser/app
COPY param.c .
COPY flag.txt .
RUN gcc -m32 -fno-stack-protector -no-pie -o param param.c 
RUN chmod 555 param && chmod 444 flag.txt && chown -R ctfuser:ctfuser /home/ctfuser
USER ctfuser
EXPOSE 5000
CMD ["socat", "TCP-LISTEN:5000,reuseaddr,fork", "EXEC:./param,stderr"]
