create table account (money integer, name text NOT NULL, kind smallint, times integer);

create table account_time (account_id integer, date_time text, times integer, primary key(account_id, date_time), constraint fk foreign key(account_id) references account(rowid));