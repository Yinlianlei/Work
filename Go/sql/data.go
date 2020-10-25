package sql

type Contract struct{
	TransactionHash string `json:"transaction_hash"`
	BlockNumber string `json:"block"`
	Timestamp string `json:"time_stamp"`
	From string  `json:"from"`
	To string `json:"to"`
	Value string `json:"value"`
	Nonce string `json:"nonce"`
	InputData string `json:"input_data"`
}