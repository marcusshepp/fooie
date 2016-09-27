import React from 'react';
import ReactDOM from 'react-dom';

import Add from './components/add';
import Subtract from './components/subtract';


class App extends React.Component {

    constructor(){
        super() 
        this.state = {count: 0}
    }

    click_subtract(){
        var new_count = this.state.count - 1;
        this.setState({count: new_count}); 
    }

    click_add(){
        var new_count = this.state.count + 1;
        this.setState({count: new_count});
    }

	render() {
		return (
            <div>
                <Add    
                    add_to_count={ this.click_add.bind(this) }/>
                { this.state.count }
                <Subtract
                    subtract_from_count={ this.click_subtract.bind(this) } />
            </div>
        );
	}

}


ReactDOM.render(<App />, document.getElementById('app'));
