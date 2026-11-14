CREATE TABLE Clients (
    client_id INTEGER PRIMARY KEY AUTOINCREMENT,
    full_name TEXT NOT NULL,
    phone_number TEXT NOT NULL UNIQUE,
    email TEXT
);

CREATE TABLE Bikes (
    bike_id INTEGER PRIMARY KEY AUTOINCREMENT,
    model TEXT NOT NULL,
    category TEXT NOT NULL,
    price_per_hour REAL NOT NULL,
    status TEXT DEFAULT 'Available'
);

CREATE TABLE Rentals (
    rental_id INTEGER PRIMARY KEY AUTOINCREMENT,
    client_id INTEGER NOT NULL,
    bike_id INTEGER NOT NULL,
    start_time DATETIME NOT NULL,
    end_time DATETIME,
    total_cost REAL,
    FOREIGN KEY (client_id) REFERENCES Clients(client_id),
    FOREIGN KEY (bike_id) REFERENCES Bikes(bike_id)
);

CREATE TABLE Payments (
    payment_id INTEGER PRIMARY KEY AUTOINCREMENT,
    rental_id INTEGER NOT NULL,
    amount REAL NOT NULL,
    payment_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    payment_method TEXT,
    FOREIGN KEY (rental_id) REFERENCES Rentals(rental_id)
);
