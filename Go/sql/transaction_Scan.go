package sql

type TransactionScan struct{
	//Id int64 `json:"id" xorm:"unsigned int not null auto_increment primary key"`
	BlockNumber string `json:"blocknumber" xorm:"not null "`
	Hash string `josn:"hash" xorm:"not null "`
	//Nonce string `json:"nonce"`
	//BlockHash string `json:"blockHash"`
	//TransactionIndex string `json:"transactionIndex"`
	From string `json:"from" xorm:"not null "`
	To string `json:"to" xorm:"not null "`
	//Value string `json:"value"`
	//GasPrice string `json:"gasPrice"`
	//Gas string `json:"gas"`
	Input string `json:"input" xorm:"not null text"`
}