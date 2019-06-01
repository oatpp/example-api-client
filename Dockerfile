FROM lganzzzo/alpine-cmake:latest

RUN apk add curl-dev

ADD . /service

WORKDIR /service/utility

RUN ./install-oatpp-modules.sh

WORKDIR /service/build

RUN cmake ..
RUN make

EXPOSE 8000 8000

ENTRYPOINT ["./example-api-client-exe"]
