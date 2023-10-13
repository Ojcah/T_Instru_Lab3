CREATE DATABASE proyecto3;

CREATE TABLE Muestra( --Tabla de Muestras
	id INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
	autor VARCHAR(32) NOT NULL,
	fecha DATE NOT NULL,
	numero_de_canal INT NOT NULL,
	unidades VARCHAR(32) NOT NULL
);

CREATE TABLE Dato( --Vector de Datos
	posicion INT NOT NULL,
	muestraId INT FOREIGN KEY (muestraId) REFERENCES Muestra(id) NOT NULL,
	valor INT NOT NULL
);

insert into Muestra(autor,fecha,numero_de_canal,unidades) values('Sebastian','2008-11-11',1,'Temperatura')	

select * from Muestra
select * from Dato

DELETE FROM Muestra WHERE id=2;