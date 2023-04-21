FROM debian:bookworm as build 
RUN apt update && apt install build-essential clang -y

COPY . /qoa
WORKDIR /qoa/fuzz
RUN make

FROM debian:bookworm
COPY --from=build /qoa/fuzz/qoa-fuzz .