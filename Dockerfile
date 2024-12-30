FROM gcc:latest

RUN apt-get update && apt-get install -y make

WORKDIR /app
COPY . /app

RUN make 

CMD ["sh", "-c", "./guessing_game $RANGE"]

# docker build -t guessing_game .
# docker run -it --rm --env-file .env guessing_game