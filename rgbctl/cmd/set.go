package cmd

import (
	"github.com/spf13/cobra"
	"github.com/2000Slash/rgbd/rgbctl/midlevel"
	"errors"
	"regexp"
	"fmt"
)

var setCmd = &cobra.Command {
	Use: "set",
	Short: "Set the Keyboard's color",
	Long: "Change the color that rgbd sets on each update.",
	Args: isValidColor,
	Run: changeColor,
}

func changeColor(cmd *cobra.Command, args[] string) {
	err := midlevel.SetAllColors(args[0])
	if err != nil {
		fmt.Println(err)
	}
}

func init() {
	rootCmd.AddCommand(setCmd)
}

func isValidColor(cmd *cobra.Command, args []string) error {
	if len(args) != 1 {
		return errors.New("The only argument must be a color");
	}
	regx := regexp.MustCompile(`^[a-fA-F0-9]{6}$`)
	input := args[0]
	if regx.MatchString(input) {
		return nil
	} else {
		return errors.New("The only argument must be a color");
	}
}
