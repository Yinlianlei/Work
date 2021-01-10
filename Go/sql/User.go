package sql

type User struct{
	Passwd string `json:"Passwd" xorm:"not null "`
	Id string `json:"Id" xorm:"not null"`
	Adress string `json:"Address" xorm:"not null"`
}