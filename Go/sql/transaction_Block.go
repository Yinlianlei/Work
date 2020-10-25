package sql

type Transaction_Block struct{
	//Id int64 `json:"id"`
	Hash string `josn:"hash"`
	Nonce string `json:"nonce"`
	BlockHash string `json:"blockHash"`
	BlockNumber string `json:"blockNumber"`
	TransactionIndex string `json:"transactionIndex"`
	From string `json:"from"`
	To string `json:"to"`
	//Value string `json:"value"`
	//GasPrice string `json:"gasPrice"`
	//Gas string `json:"gas"`
	Input string `xorm:"text" json:"input"`
}