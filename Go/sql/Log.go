package sql

type Log struct{
	BlockNumber string `json:"blockNumber" xorm:"not null varchar(255)"`
	BlockHash string `json:"blockHash" xorm:"not null "`
	Address string `json:"address" gencodec:"required"  xorm:"not null "`
	Topics []string `json:"topics" gencodec:"required" xorm:"not null "`
	Data string `json:"data" gencodec:"required" xorm:"not null "`
	TxHash string`json:"transactionHash" gencodec:"required" xorm:"not null "`
	TxIndex string `json:"transactionIndex" xorm:"not null VARCHAR(255) "`
	Index string `json:"logIndex" xorm:"not null VARCHAR(255)"`
	Removed bool `json:"removed" xorm:"not null "`
}
/*
type LOG struct{
	BlockHash string `json:"block_hash"`
	BlockNumber string `json:"block_number"`
	ContractAddress string `json:"contract_address"`
	Timestamp string `json:"time_stamp"`
	From string `json:"from"`
	To string `josn:"to"`
	Logs []types.Log `json:"logs"`

}
*/