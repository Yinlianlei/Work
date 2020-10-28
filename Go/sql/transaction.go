package sql

type Transaction struct{
	Id int64 `json:"id" xorm:"not null "`
	Hash string `josn:"hash" xorm:"not null "`
	Nonce string `json:"nonce" xorm:"not null "`
	BlockHash string `json:"blockHash" xorm:"not null "`
	BlockNumber string `json:"blockNumber" xorm:"not null "`
	TransactionIndex string `json:"transactionIndex" xorm:"not null "`
	From string `json:"from" xorm:"not null "`
	To string `json:"to" xorm:"not null "`
	Value string `json:"value" xorm:"not null "`
	GasPrice string `json:"gasPrice" xorm:"not null "`
	Gas string `json:"gas" xorm:"not null "`
	Input string `xorm:"text" json:"input" xorm:"not null "`
}