show databases;
use sys;
drop database if exists minercoffee;
create database minercoffee;
use minercoffee;
drop table if exists main_table;
create table main_table(
	Date1 date not null,
	Time1 time not null,
    hashrate float4 not null,
	accepted_shares int not null,
    invalid_shares int not null,
    rejected_shares int not null,
    gpu_name TEXT not null,
    TMP int not null,
    gpu_clock int not null,
    mem_clock int not null,
    FanSpeed int not null,
    PowerDraw int not null,
	gpu_id int not null,
    primary key(gpu_id,Date1,Time1)
);
create table advise(gpu_type varchar(10) PRIMARY KEY,gpu_clock int,mem_clock int not null,power int not null,prediction int not null);
insert into advise values('3090',-300,1000,285,120);
insert into advise values('3080',-150,900,220,98);
insert into advise values('3070',-500,1100,130,60);
insert into advise values('3060Ti',-500,1200,130,60);
insert into advise values('2080Ti',-200,1100,150,57);
insert into advise values('2080super',-50,1000,175,42);
insert into advise values('2080',-50,800,155,42);
insert into advise values('2070super',-50,800,150,40);
insert into advise values('2070',-50,800,125,39);
insert into advise values('2060super',-50,850,125,39);
insert into advise values('2060',-50,700,115,31);
insert into advise values('1080Ti',null,800,175,45);
insert into advise values('1080',null,800,125,43);
insert into advise values('1070Ti',null,500,135,30);
insert into advise values('1070',null,450,115,30);
insert into advise values('1060',null,900,80,23);
show tables;
select * from main_table;
select gpu_clock,mem_clock,power,prediction from advise where gpu_type='2070';
insert into main_table values('2021-4-18','17:25:36',-536870912,0,0,0,45,300,405,0,11961,0) ;
insert into main_table values('2021-4-18','17:24:30',-536870912,0,0,0,46,300,405,0,11556,0) ;
select avg(TMP),avg(gpu_clock),avg(mem_clock),avg(FanSpeed),avg(PowerDraw),avg(hashrate) from main_table where Date1<='2021-04-18' and Date1>='2021-04-18' and gpu_id=0;
select avg(TMP),avg(gpu_clock),avg(mem_clock),avg(FanSpeed),avg(PowerDraw),avg(hashrate) from main_table where Date1<='2021-04-18' and Date1>='2021-04-18' and gpu_id=0;