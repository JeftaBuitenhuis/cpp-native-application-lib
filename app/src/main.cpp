void main() {
    // init platform dependend window

    // render loading screen

    // load data & get connection

    // render main menu screen

    // opt: 1 -> settings

        // render settings screen

            // opt: 1 -> change setting

                // change setting

            // opt: 2 -> save & quit

                // continue

            // opt: 3 -> quit

                // if changed setting: are you sure

                    // opt: 1 -> yes

                        // continue

                    // opt: 2 -> no

                        // return

    // opt: 2 -> play

        // load game save / level select

            // opt: 1 -> game save / level selected
            
                // call loading screen

                // load data

                // call game renderer

                // call game logic
                

            // opt: 2 -> return

    // opt: 3 -> quit

        // terminate app
    
}