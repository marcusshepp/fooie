import React from 'react';

import Label from './label';

export default class SelectInput extends React.Component {
	render(){
		return(
			<div>
				<Label 
					text={ this.props.label_text } 
					/>
				<select name={ this.props.name }>
					{ this.props.options.map(function(option){
						return (
							<option 
								key={ option.value }
								value={ option.value }>
								{ option.display_name }
							</option>
						);
					}) }
				</select>
			</div>
		);
	}
}
