package sql

type Log struct{
	Address string `json:"address" gencodec:"required"`
	Topics []string `json:"topics" gencodec:"required"`
	Data []byte `json:"data" gencodec:"required"`
	BlockNumber uint64 `json:"blockNumber"`
	TxHash string`json:"transactionHash" gencodec:"required"`
	TxIndex uint `json:"transactionIndex"`
	BlockHash string `json:"blockHash"`
	Index uint64 `json:"logIndex"`
	Removed bool `json:"removed"`
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