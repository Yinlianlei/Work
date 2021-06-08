package sql;

import "time"

type Wx_copyright struct{
	Id       uint      `json:"id" xorm:"pk autoincr unique"` //pk:primary key  autoincr:auto_increment
	Owner    string    `json:"owner" xorm:"not null varchar(30)"`
	FileName string    `json:"fileName" xorm:"not null varchar(255)"`
	Hash     string	   `json:"Hash" xorm:"not null varchar(255)"`
	FileID   string    `json:"fileID"  xorm:"not null varchar(255)"`
	Time     time.Time	 `json:"time" xorm:"not null"`
	TxID     string    `json:"TxID" xorm:"not null varchar(255)"`
}

type Wx_user struct{
	Owner string `json:"owner" xorm:"pk unique varchar(30)"`
	Pwd string `json:"pwd" xorm:"not null varchar(255)"`
	Introduce string `json:"introduce"  xorm:"not null varchar(255)"`
	Income float64 `json:"income" xorm:"not null double"`
}

type Wx_purchase struct{
	Id       uint   `json:"id" xorm:"pk autoincr unique"` //pk:primary key  autoincr:auto_increment
	Owner    string `json:"owner" xorm:"not null varchar(30)"`
	Purchase string `json:"purchase" xorm:"not null varchar(30)"`
	Hash     string	   `json:"Hash" xorm:"not null varchar(255)"`
	Price    float64 `json:"price"  xorm:"not null double"`
	TxID     string `json:"TxID" xorm:"not null varchar(255)"`
}

/*
To string `json:"to" gencodec:"required" xorm:"not null "`
	Data []string `json:"data" gencodec:"required" xorm:"not null "`
	TxHash string`json:"transactionHash" gencodec:"required" xorm:"not null "`
	TxIndex string `json:"transactionIndex" xorm:"not null VARCHAR(255) "`
	Index string `json:"logIndex" xorm:"not null VARCHAR(255)"`
	Removed bool `json:"removed" xorm:"not null "`
*/