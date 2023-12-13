FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    readpe

WORKDIR /app

COPY . /app

RUN make

CMD ["./your_app"]