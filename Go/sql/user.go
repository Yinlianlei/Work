package sql

type User struct{
	Id string `json:"Id" xorm:"unique not null"`
	Passwd string `json:"Passwd" xorm:"not null"`
	Address string `json:"Adrress" xorm:"not null"`
}