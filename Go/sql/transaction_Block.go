package sql

type Transaction_Block struct{
	//Id int64 `json:"id"`
	Hash string `josn:"hash" xorm:"not null "`
	Nonce string `json:"nonce" xorm:"not null "`
	BlockHash string `json:"blockHash" xorm:"not null "`
	BlockNumber string `json:"blockNumber" xorm:"not null "`
	TransactionIndex string `json:"transactionIndex" xorm:"not null "`
	From string `json:"from" xorm:"not null "`
	To string `json:"to" xorm:"not null "`
	//Value string `json:"value"`
	//GasPrice string `json:"gasPrice"`
	//Gas string `json:"gas"`
	Input string `xorm:"text" json:"input" xorm:"not null "`
}