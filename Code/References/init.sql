drop table if exists main_table;
create table gpu_table(
	gpu_id int PRIMARY KEY,
	GPU_TMP int not null,
    GPU_cLOCK int not null,
    FanSpeed int not null,
    PowerDraw int not null,
    Drawsum int not null
);
create table hash_table(
    gpu_id int PRIMARY KEY,
    hashrate float4 not null,
	accepted_shares int not null,
    invalid_shares int not null,
    rejected_shares int not null
);
create table main_table(
	Date1 date not null,
	Time1 time not null,
    gpu_id int PRIMARY KEY not null,
    gpu_name varchar(8) not null,
    FOREIGN KEY(gpu_id) REFERENCES gpu_table(gpu_id),
    FOREIGN KEY(gpu_id) REFERENCES hash_table(gpu_id)
);
create table advise(
	gou_type varchar(10) PRIMARY KEY,
    gpu_clock int,
    mem_clock int not null,
    power int not null,
    prediction int not null
);

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

select * from advise;
