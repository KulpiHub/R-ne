-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description, id FROM crime_scene_reports
WHERE description LIKE "%CS50%";

SELECT * FROM crime_scene_reports WHERE id = 295;
-- bakery mentioned

SELECT id FROM crime_scene_reports WHERE street LIKE "%Humphrey%" AND day = 28 AND month = 28 AND YEAR = 2021;

SELECT * FROM crime_scene_reports WHERE id = 297; -- nothing relevant

SELECT * FROM interviews WHERE day = 28 AND month = 07 AND year = 2021; -- interviews 161, 162, 163 seem relevant, check parking lot, atm, earliest flight from fiftyville (29.07.2021), 10 minutes after theft (10.25 check phone, check parking lot, check atm before theft), Legget Street ATM

SELECT * FROM airports WHERE city = "Fiftyville"; -- airport ID = 8

SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 07
ORDER BY hour ASC; -- earlies flight at 8.20 to origin_airport_id = 4, flight id = 36;

SELECT * FROM airports WHERE ID = 4; -- LaGuardia Airport, NY

select * from bakery_security_logs where day = 28 and month = 07;

select * from people where license_plate = "G412CB7";

select * from passengers where passport_number = "1695452385";

select * from phone_calls where caller = "(130) 555-0289" and day = 28 and month = 07;

select name from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
where atm_transactions.year = 2021
and atm_transactions.day = 28
and atm_transactions.month = 07
and atm_transactions.transaction_type = "withdraw"
and atm_transactions.atm_location = "Leggett Street";

-- transaction names
--+---------+
--|  name   |
--+---------+
--| Bruce   |
--| Diana   |
--| Brooke  |
--| Kenny   |
--| Iman    |
--| Luca    |
--| Taylor  |
--| Benista |
--+---------+

select name, people.passport_number from people
join passengers on passengers.passport_number = people.passport_number
join flights on passengers.flight_id = flights.id
where flights.id = 36;

-- flights
+--------+-----------------+
|  name  | passport_number |
+--------+-----------------+
| Doris  | 7214083635      |
| Sofia  | 1695452385      |
| Bruce  | 5773159633      |
| Edward | 1540955065      |
| Kelsey | 8294398571      |
| Taylor | 1988161715      |
| Kenny  | 9878712108      |
| Luca   | 8496433585      |
+--------+-----------------+

select name, people.license_plate from people
join bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
where bakery_security_logs.day = 28
and bakery_security_logs.month = 07
and bakery_security_logs.year = 2021
and bakery_security_logs.activity = "exit"
and bakery_security_logs.hour = 10
and bakery_security_logs.minute between 15 and 25;


-- person and license plate during theft
+---------+---------------+
|  name   | license_plate |
+---------+---------------+
| Vanessa | 5P2BI95       |
| Bruce   | 94KL13X       |
| Barry   | 6P58WS2       |
| Luca    | 4328GD8       |
| Sofia   | G412CB7       |
| Iman    | L93JTIZ       |
| Diana   | 322W7JE       |
| Kelsey  | 0NTHK55       |
+---------+---------------+


select name, people.phone_number, phone_calls.duration, phone_calls.receiver from people
join phone_calls on phone_calls.caller = people.phone_number
where phone_calls.day = 28
and phone_calls.month = 07
and phone_calls.year = 2021
and phone_calls.duration <= 60;

-- phone calls
+------------+----------------+----------+----------------+
|    name    |  phone_number  | duration |     caller     |
+------------+----------------+----------+----------------+
| Jack       | (996) 555-8899 | 51       | (130) 555-0289 |
| Larry      | (892) 555-8872 | 36       | (499) 555-9472 |
| Robin      | (375) 555-8161 | 45       | (367) 555-5533 |
| Luca       | (389) 555-5198 | 60       | (609) 555-5876 |
| Melissa    | (717) 555-1342 | 50       | (499) 555-9472 |
| James      | (676) 555-6554 | 43       | (286) 555-6063 |
| Philip     | (725) 555-3243 | 49       | (770) 555-1861 |
| Jacqueline | (910) 555-3251 | 38       | (031) 555-6622 |
| Doris      | (066) 555-9701 | 55       | (826) 555-1652 |
| Anna       | (704) 555-2131 | 54       | (338) 555-6650 |
+------------+----------------+----------+----------------+
+---------+----------------+----------+----------------+
|  name   |  phone_number  | duration |    receiver    |
+---------+----------------+----------+----------------+
| Sofia   | (130) 555-0289 | 51       | (996) 555-8899 |
| Kelsey  | (499) 555-9472 | 36       | (892) 555-8872 |
| Bruce   | (367) 555-5533 | 45       | (375) 555-8161 |
| Kathryn | (609) 555-5876 | 60       | (389) 555-5198 |
| Kelsey  | (499) 555-9472 | 50       | (717) 555-1342 |
| Taylor  | (286) 555-6063 | 43       | (676) 555-6554 |
| Diana   | (770) 555-1861 | 49       | (725) 555-3243 |
| Carina  | (031) 555-6622 | 38       | (910) 555-3251 |
| Kenny   | (826) 555-1652 | 55       | (066) 555-9701 |
| Benista | (338) 555-6650 | 54       | (704) 555-2131 |
+---------+----------------+----------+----------------+

-- Bruce appears in every table