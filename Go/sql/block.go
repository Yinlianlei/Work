package sql

type Block struct{
	Id int64 `json:"id" xorm:"not null "`
	BlockNumber string `json:"block_number" xorm:"not null "`
	BlockHash string `json:"block_hash" xorm:"not null "`
	ParentHash string `json:"parent_hash" xorm:"not null "`
	CreateTime int64 `json:"create_time" xorm:"not null "`
	Fork bool `json:"fork" xorm:"not null "`
}