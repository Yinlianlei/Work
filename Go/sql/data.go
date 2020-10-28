package sql

type Contract struct{
	TransactionHash string `json:"transaction_hash" xorm:"not null "`
	BlockNumber string `json:"block" xorm:"not null "`
	Timestamp string `json:"time_stamp" xorm:"not null "`
	From string  `json:"from" xorm:"not null "`
	To string `json:"to" xorm:"not null "`
	Value string `json:"value" xorm:"not null "`
	Nonce string `json:"nonce" xorm:"not null "`
	InputData string `json:"input_data" xorm:"not null "`
}