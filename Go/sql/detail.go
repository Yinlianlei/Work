package sql

import "time"

type Detail struct{
	Title string `json:"title" xorm:"unique not null varchar(255)"`
	Word string `json:"word" xorm:"not null varchar(255)"`
	Tags []string `json:"tags"`
	Author string `json:"author" xorm:"not null"`
	Address string `json:"adrress" xorm:"not null"`
	Time time.Time `json:"time" xorm:"not null"`
	DeleteTF bool `json:"deletetf" xorm:"not null"`
}
