package cmd

import (
	"github.com/spf13/cobra"
	"github.com/2000Slash/rgbd/rgbctl/midlevel"
)

var exitCmd = &cobra.Command{
	Use:   "exit",
	Short: "kill the rgb daemon",
	Long:  `Sends a 0 to the rgbd socket, which will stop gracefully`,
	Run: func(cmd *cobra.Command, args []string) {
		midlevel.Exit();
	},
}

func init() {
	rootCmd.AddCommand(exitCmd)
}
