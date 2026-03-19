CREATE TABLE IF NOT EXISTS Cinema (
    id          SERIAL PRIMARY KEY,
    name        VARCHAR(100) NOT NULL,
    city        VARCHAR(100) NOT NULL,
    postalCode  VARCHAR(6) NOT NULL,
    houseNumber VARCHAR(10) NOT NULL
);

CREATE TABLE IF NOT EXISTS Room (
    id          SERIAL PRIMARY KEY,
    seatsNum    INTEGER NOT NULL,
    cinemaId    INTEGER NOT NULL REFERENCES Cinema(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS Movie (
    id          SERIAL PRIMARY KEY,
    title       VARCHAR(200) NOT NULL,
    description TEXT,
    duration    INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS Schedule (
    id          SERIAL PRIMARY KEY,
    roomId      INTEGER NOT NULL REFERENCES Room(id) ON DELETE CASCADE,
    movieId     INTEGER NOT NULL REFERENCES Movie(id) ON DELETE CASCADE,
    date        DATE NOT NULL,
    time        TIME NOT NULL
);

CREATE TABLE IF NOT EXISTS Client (
    id          SERIAL PRIMARY KEY,
    name        VARCHAR(100) NOT NULL,
    surname     VARCHAR(100) NOT NULL,
    email       VARCHAR(200) UNIQUE NOT NULL,
    number      VARCHAR(20)
);

CREATE TABLE IF NOT EXISTS TicketType (
    id          SERIAL PRIMARY KEY,
    type        VARCHAR(50) NOT NULL,
    price       NUMERIC(8, 2) NOT NULL
);

CREATE TABLE IF NOT EXISTS Ticket (
    id          SERIAL PRIMARY KEY,
    scheduleId  INTEGER NOT NULL REFERENCES Schedule(id) ON DELETE CASCADE,
    clientId    INTEGER NOT NULL REFERENCES Client(id) ON DELETE CASCADE,
    ticketTypeId    INTEGER NOT NULL REFERENCES TicketType(id) ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS Employee (
    id          SERIAL PRIMARY KEY,
    cinemaId    INTEGER NOT NULL REFERENCES Cinema(id) ON DELETE CASCADE,
    name        VARCHAR(100) NOT NULL,
    surname     VARCHAR(100) NOT NULL,
    number      VARCHAR(20),
    email       VARCHAR(200) UNIQUE NOT NULL
);