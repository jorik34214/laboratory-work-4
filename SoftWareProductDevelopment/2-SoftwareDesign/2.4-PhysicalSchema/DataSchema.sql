CREATE TABLE PhysicalTherapist (
    prizvyshche VARCHAR(50) PRIMARY KEY,
    katehoriya VARCHAR(30) CHECK (katehoriya ~ '^[A-АІЇЄҐa-zа-іїєґ\s\-]+$')
);

CREATE TABLE Patient (
    prizvyshche VARCHAR(50) PRIMARY KEY,
    posada VARCHAR(30),
    terapevt_prizvyshche VARCHAR(50) REFERENCES PhysicalTherapist(prizvyshche)
);

CREATE TABLE Exercise (
    nazva VARCHAR(100) PRIMARY KEY,
    opys VARCHAR(500)
);

CREATE TABLE Session (
    data VARCHAR(10) PRIMARY KEY CHECK (data ~ '^(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.\d{4}$'),
    tryvalist INTEGER CHECK (tryvalist > 0),
    pacijent_prizvyshche VARCHAR(50) REFERENCES Patient(prizvyshche),
    vprava_nazva VARCHAR(100) REFERENCES Exercise(nazva)
);

CREATE TABLE JointMeasurement (
    id SERIAL PRIMARY KEY,
    kut_vyhynu REAL CHECK (kut_vyhynu >= 0 AND kut_vyhynu <= 180),
    asymetrija_khody REAL CHECK (asymetrija_khody >= 0 AND asymetrija_khody <= 100),
    seans_data VARCHAR(10) REFERENCES Session(data)
);
