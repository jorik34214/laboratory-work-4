BEGIN;
SELECT * FROM programlang WHERE pl_id = 1 FOR UPDATE;


BEGIN;
SELECT * FROM programlang WHERE pl_id = 2 FOR UPDATE;

UPDATE programlang SET name = 'Stepanenko', year = 2025 WHERE pl_id = 2;

UPDATE programlang SET name = 'С', year = 1969 WHERE pl_id = 1;
